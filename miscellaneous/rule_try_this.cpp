#include <NTL/ZZ_p.h>
#include <NTL/mat_ZZ_p.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <random>
#include <climits>

using namespace std;
using namespace NTL;
using namespace std::chrono;

struct MatrixData {
    vector<vector<long>> matrix;
    bool isNonSingular;
    ZZ_p determinant;
    
    MatrixData(const vector<vector<long>>& m, bool nonSing, const ZZ_p& det) 
        : matrix(m), isNonSingular(nonSing), determinant(det) {}
};

class EnhancedMatrixGenerator {
private:
    long prime;
    int n;
    long targetSum;
    vector<vector<long>> validRows;
    vector<MatrixData> singularMatrices;
    vector<MatrixData> nonSingularMatrices;
    vector<vector<long>> allGeneratedMatrices;
    
    // Timing variables
    high_resolution_clock::time_point startTime;
    high_resolution_clock::time_point rowGenTime;
    high_resolution_clock::time_point matrixGenTime;
    
public:
    EnhancedMatrixGenerator(long p, int size) : prime(p), n(size), targetSum(p-1) {
        try {
            if (!ProbPrime(ZZ(p))) {
                throw invalid_argument("Input must be a prime number");
            }
            if (size <= 0 || size > 10) {
                throw invalid_argument("Matrix size must be between 1 and 10");
            }
            if (p <= size) {
                throw invalid_argument("Prime must be greater than matrix size");
            }
            
            ZZ_p::init(ZZ(p));
            cout << "Initialized with prime p = " << p << ", matrix size = " << size << "x" << size << endl;
            cout << "Target row sum = " << targetSum << endl;
            
            // Check feasibility
            if (static_cast<long long>(size) * size > p) {
                cout << "Warning: Need " << (size*size) << " unique elements but only " 
                     << p << " values available (0 to " << (p-1) << ")" << endl;
            }
            
        } catch (const exception& e) {
            throw runtime_error("Initialization failed: " + string(e.what()));
        }
    }
    
    void startTiming() {
        startTime = high_resolution_clock::now();
    }
    
    double getElapsedTime() {
        auto now = high_resolution_clock::now();
        return duration_cast<milliseconds>(now - startTime).count() / 1000.0;
    }
    
    // Generate all valid rows where sum = p-1
    void generateValidRows() {
        cout << "\n=== Step 1: Generating Valid Rows ===" << endl;
        auto stepStart = high_resolution_clock::now();
        
        validRows.clear();
        vector<long> currentRow;
        set<vector<long>> uniqueRows; // To avoid duplicates
        
        try {
            generateRowsRecursive(currentRow, 0, 0, uniqueRows);
            
            // Convert set to vector
            validRows.assign(uniqueRows.begin(), uniqueRows.end());
            
            rowGenTime = high_resolution_clock::now();
            double elapsed = duration_cast<milliseconds>(rowGenTime - stepStart).count() / 1000.0;
            
            cout << "✓ Generated " << validRows.size() << " unique valid rows in " << elapsed << " seconds" << endl;
            
            if (validRows.empty()) {
                throw runtime_error("No valid rows found with given constraints");
            }
            
            // Display sample rows
            cout << "\nSample valid rows (showing first 10):" << endl;
            for (size_t i = 0; i < min(static_cast<size_t>(10), validRows.size()); i++) {
                cout << "Row " << (i+1) << ": [";
                for (int j = 0; j < n; j++) {
                    cout << validRows[i][j];
                    if (j < n-1) cout << ", ";
                }
                long sum = accumulate(validRows[i].begin(), validRows[i].end(), 0L);
                cout << "] sum=" << sum << endl;
            }
            
        } catch (const exception& e) {
            throw runtime_error("Row generation failed: " + string(e.what()));
        }
    }
    
private:
    void generateRowsRecursive(vector<long>& currentRow, int position, long currentSum, 
                              set<vector<long>>& uniqueRows) {
        if (position == n) {
            if (currentSum == targetSum) {
                uniqueRows.insert(currentRow);
            }
            return;
        }
        
        long remaining = targetSum - currentSum;
        int remainingPositions = n - position;
        
        // Pruning: check bounds
        if (remaining < 0 || remaining > remainingPositions * (prime - 1)) {
            return;
        }
        
        for (long val = 0; val < prime; val++) {
            // Check if adding this value is feasible
            long newSum = currentSum + val;
            long stillRemaining = targetSum - newSum;
            int stillRemainingPositions = remainingPositions - 1;
            
            if (stillRemainingPositions == 0) {
                if (newSum == targetSum) {
                    currentRow.push_back(val);
                    generateRowsRecursive(currentRow, position + 1, newSum, uniqueRows);
                    currentRow.pop_back();
                }
            } else if (stillRemaining >= 0 && stillRemaining <= stillRemainingPositions * (prime - 1)) {
                currentRow.push_back(val);
                generateRowsRecursive(currentRow, position + 1, newSum, uniqueRows);
                currentRow.pop_back();
            }
        }
    }
    
public:
    bool hasUniqueElements(const vector<vector<long>>& matrix) {
        set<long> elements;
        for (const auto& row : matrix) {
            for (long val : row) {
                if (elements.count(val)) {
                    return false;
                }
                elements.insert(val);
            }
        }
        return elements.size() == static_cast<size_t>(n * n);
    }
    
    pair<bool, ZZ_p> checkSingularity(const vector<vector<long>>& matrix) {
        try {
            mat_ZZ_p M;
            M.SetDims(n, n);
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    M[i][j] = ZZ_p(matrix[i][j]);
                }
            }
            
            ZZ_p det = determinant(M);
            return make_pair(!IsZero(det), det);
            
        } catch (const exception& e) {
            throw runtime_error("Determinant calculation failed: " + string(e.what()));
        }
    }
    
    void generateMatrices(long maxMatrices = LONG_MAX) {
        if (validRows.empty()) {
            throw runtime_error("No valid rows available. Run generateValidRows() first.");
        }
        
        cout << "\n=== Step 2: Generating and Analyzing Matrices ===" << endl;
        auto stepStart = high_resolution_clock::now();
        
        singularMatrices.clear();
        nonSingularMatrices.clear();
        allGeneratedMatrices.clear();
        
        long totalCombinations = 1;
        for (int i = 0; i < n; i++) {
            totalCombinations *= validRows.size();
            if (totalCombinations > maxMatrices) {
                totalCombinations = maxMatrices;
                break;
            }
        }
        
        cout << "Target: " << min(maxMatrices, totalCombinations) << " matrices" << endl;
        cout << "Available row combinations: " << totalCombinations << endl;
        
        long processedCount = 0;
        long validCount = 0;
        vector<int> indices(n, 0);
        
        try {
            // Use systematic generation up to maxMatrices
            bool done = false;
            while (!done && processedCount < maxMatrices) {
                // Create matrix from current indices
                vector<vector<long>> matrix(n);
                for (int i = 0; i < n; i++) {
                    matrix[i] = validRows[indices[i]];
                }
                
                processedCount++;
                allGeneratedMatrices.push_back(matrix);
                
                // Check uniqueness
                if (hasUniqueElements(matrix)) {
                    validCount++;
                    
                    // Check singularity
                    auto [isNonSing, det] = checkSingularity(matrix);
                    
                    if (isNonSing) {
                        nonSingularMatrices.emplace_back(matrix, true, det);
                    } else {
                        singularMatrices.emplace_back(matrix, false, det);
                    }
                }
                
                // Progress reporting
                if (processedCount % 1000 == 0) {
                    cout << "Processed: " << processedCount << "/" << maxMatrices 
                         << " (" << (processedCount * 100 / maxMatrices) << "%)" << endl;
                }
                
                // Generate next combination
                done = !nextCombination(indices);
            }
            
        } catch (const exception& e) {
            throw runtime_error("Matrix generation failed: " + string(e.what()));
        }
        
        matrixGenTime = high_resolution_clock::now();
        double elapsed = duration_cast<milliseconds>(matrixGenTime - stepStart).count() / 1000.0;
        
        cout << "\n✓ Matrix generation completed in " << elapsed << " seconds" << endl;
        cout << "Total matrices processed: " << processedCount << endl;
        cout << "Valid matrices (unique elements): " << validCount << endl;
        cout << "Non-singular matrices: " << nonSingularMatrices.size() << endl;
        cout << "Singular matrices: " << singularMatrices.size() << endl;
    }
    
private:
    bool nextCombination(vector<int>& indices) {
        for (int i = n - 1; i >= 0; i--) {
            if (indices[i] < static_cast<int>(validRows.size()) - 1) {
                indices[i]++;
                return true;
            }
            indices[i] = 0;
        }
        return false;
    }
    
public:
    void saveResults(const string& filename = "matrix_results.txt") {
        cout << "\n=== Step 3: Saving Results ===" << endl;
        auto saveStart = high_resolution_clock::now();
        
        try {
            ofstream file(filename);
            if (!file.is_open()) {
                throw runtime_error("Cannot open file for writing: " + filename);
            }
            
            file << "Matrix Analysis Results\n";
            file << "=======================\n";
            file << "Prime p = " << prime << "\n";
            file << "Matrix size = " << n << "x" << n << "\n";
            file << "Target row sum = " << targetSum << "\n\n";
            
            // Save valid rows
            file << "Valid Rows (" << validRows.size() << " total):\n";
            file << "----------------------------------------\n";
            for (size_t i = 0; i < validRows.size(); i++) {
                file << "Row " << (i+1) << ": [";
                for (int j = 0; j < n; j++) {
                    file << validRows[i][j];
                    if (j < n-1) file << ", ";
                }
                file << "]\n";
            }
            file << "\n";
            
            // Save non-singular matrices
            file << "Non-Singular Matrices (" << nonSingularMatrices.size() << " total):\n";
            file << "------------------------------------------------\n";
            for (size_t i = 0; i < nonSingularMatrices.size(); i++) {
                file << "Matrix " << (i+1) << " (det = " << nonSingularMatrices[i].determinant << "):\n";
                for (int row = 0; row < n; row++) {
                    file << "[";
                    for (int col = 0; col < n; col++) {
                        file << nonSingularMatrices[i].matrix[row][col];
                        if (col < n-1) file << ", ";
                    }
                    file << "]\n";
                }
                file << "\n";
            }
            
            // Save singular matrices
            file << "Singular Matrices (" << singularMatrices.size() << " total):\n";
            file << "--------------------------------------------\n";
            for (size_t i = 0; i < singularMatrices.size(); i++) {
                file << "Matrix " << (i+1) << " (det = " << singularMatrices[i].determinant << "):\n";
                for (int row = 0; row < n; row++) {
                    file << "[";
                    for (int col = 0; col < n; col++) {
                        file << singularMatrices[i].matrix[row][col];
                        if (col < n-1) file << ", ";
                    }
                    file << "]\n";
                }
                file << "\n";
            }
            
            file.close();
            
            auto saveEnd = high_resolution_clock::now();
            double elapsed = duration_cast<milliseconds>(saveEnd - saveStart).count() / 1000.0;
            
            cout << "✓ Results saved to '" << filename << "' in " << elapsed << " seconds" << endl;
            
        } catch (const exception& e) {
            throw runtime_error("Failed to save results: " + string(e.what()));
        }
    }
    
    void printSummary() {
        cout << "\n=== FINAL SUMMARY ===" << endl;
        cout << "Total computation time: " << getElapsedTime() << " seconds" << endl;
        cout << "Prime p: " << prime << endl;
        cout << "Matrix size: " << n << "x" << n << endl;
        cout << "Target row sum: " << targetSum << endl;
        cout << "\nGenerated data:" << endl;
        cout << "- Valid rows: " << validRows.size() << endl;
        cout << "- Total matrices processed: " << allGeneratedMatrices.size() << endl;
        cout << "- Non-singular matrices: " << nonSingularMatrices.size() << endl;
        cout << "- Singular matrices: " << singularMatrices.size() << endl;
        
        long totalValid = nonSingularMatrices.size() + singularMatrices.size();
        if (totalValid > 0) {
            cout << "- Non-singular ratio: " << (100.0 * nonSingularMatrices.size() / totalValid) << "%" << endl;
        }
        
        // Memory usage estimation
        size_t memoryUsage = validRows.size() * n * sizeof(long) +
                           (nonSingularMatrices.size() + singularMatrices.size()) * n * n * sizeof(long);
        cout << "- Estimated memory usage: " << (memoryUsage / 1024.0 / 1024.0) << " MB" << endl;
    }
    
    // Display sample matrices
    void showSampleMatrices(int numSamples = 3) {
        cout << "\n=== Sample Matrices ===" << endl;
        
        cout << "Non-singular matrices (showing " << min(numSamples, static_cast<int>(nonSingularMatrices.size())) << "):" << endl;
        for (int i = 0; i < min(numSamples, static_cast<int>(nonSingularMatrices.size())); i++) {
            cout << "Matrix " << (i+1) << " (det = " << nonSingularMatrices[i].determinant << "):" << endl;
            for (int row = 0; row < n; row++) {
                cout << "[";
                for (int col = 0; col < n; col++) {
                    cout << nonSingularMatrices[i].matrix[row][col];
                    if (col < n-1) cout << ", ";
                }
                cout << "]" << endl;
            }
            cout << endl;
        }
        
        cout << "Singular matrices (showing " << min(numSamples, static_cast<int>(singularMatrices.size())) << "):" << endl;
        for (int i = 0; i < min(numSamples, static_cast<int>(singularMatrices.size())); i++) {
            cout << "Matrix " << (i+1) << " (det = " << singularMatrices[i].determinant << "):" << endl;
            for (int row = 0; row < n; row++) {
                cout << "[";
                for (int col = 0; col < n; col++) {
                    cout << singularMatrices[i].matrix[row][col];
                    if (col < n-1) cout << ", ";
                }
                cout << "]" << endl;
            }
            cout << endl;
        }
    }
};

int main() {
    try {
        long prime;
        int matrixSize;
        long maxMatrices;
        string filename;
        
        cout << "Enhanced Matrix Analysis with NTL ZZ_p" << endl;
        cout << "=====================================" << endl;
        
        cout << "Enter prime number p: ";
        cin >> prime;
        
        cout << "Enter matrix size n: ";
        cin >> matrixSize;
        
        cout << "Enter maximum number of matrices to generate (0 for all): ";
        cin >> maxMatrices;
        if (maxMatrices <= 0) maxMatrices = LONG_MAX;
        
        cout << "Enter output filename (default: matrix_results.txt): ";
        cin.ignore();
        getline(cin, filename);
        if (filename.empty()) filename = "matrix_results.txt";
        
        // Initialize generator
        EnhancedMatrixGenerator generator(prime, matrixSize);
        generator.startTiming();
        
        // Generate and analyze
        generator.generateValidRows();
        generator.generateMatrices(maxMatrices);
        generator.showSampleMatrices();
        generator.saveResults(filename);
        generator.printSummary();
        
        cout << "\n✓ Analysis completed successfully!" << endl;
        
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    } catch (...) {
        cerr << "Unknown error occurred" << endl;
        return 1;
    }
    
    return 0;
}