#include <NTL/ZZ_p.h>
#include <NTL/mat_ZZ_p.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <set>
#include <iomanip>
using namespace std;
using namespace NTL;
// version 8
class ProgressBar {
private:
    int width;
    string description;
    
public:
    ProgressBar(int w = 50, string desc = "Progress") : width(w), description(desc) {}
    
    void update(double progress, long current, long total) {
        int pos = width * progress;
        cout << "\r" << description << ": [";
        for (int i = 0; i < width; ++i) {
            if (i < pos) cout << "=";
            else if (i == pos) cout << ">";
            else cout << " ";
        }
        cout << "] " << int(progress * 100.0) << "% (" << current << "/" << total << ")";
        cout.flush();
    }
    
    void finish() {
        cout << endl;
    }
};

// Generate all possible rows of length 4 with unique elements from 1 to p, sum = p-1
void generateValidRows(vector<vector<long>>& validRows, vector<long>& currentRow, 
                       vector<bool>& used, long pos, long p, long currentSum) {
    if (pos == 4) {
        if (currentSum == p - 1) {
            validRows.push_back(currentRow);
        }
        return;
    }
    
    // Pruning: check if target sum is achievable
    long remaining = 4 - pos;
    
    // Calculate available values
    vector<long> available;
    for (long i = 1; i <= p; i++) {
        if (!used[i]) {
            available.push_back(i);
        }
    }
    
    if (available.size() < remaining) {
        return; // Not enough unused values
    }
    
    // Calculate bounds
    sort(available.begin(), available.end());
    long minPossible = currentSum;
    long maxPossible = currentSum;
    
    for (long i = 0; i < remaining && i < available.size(); i++) {
        minPossible += available[i];
    }
    
    for (long i = max(0L, (long)available.size() - remaining); i < available.size(); i++) {
        maxPossible += available[i];
    }
    
    if (minPossible > p - 1 || maxPossible < p - 1) {
        return; // Cannot reach target sum
    }
    
    // Try each unused value
    for (long val = 1; val <= p; val++) {
        if (!used[val]) {
            currentRow[pos] = val;
            used[val] = true;
            generateValidRows(validRows, currentRow, used, pos + 1, p, currentSum + val);
            used[val] = false;
        }
    }
}

// Generate all combinations of 4 rows from validRows to form 4x4 matrices
void generateMatrixCombinations(const vector<vector<long>>& validRows, long p,
                               long& singularCount, long& nonsingularCount) {
    
    ZZ_p::init(p);
    
    long totalCombinations = 0;
    long validMatrices = 0;
    
    // Calculate total possible combinations
    long n = validRows.size();
    long totalPossible = n * (n-1) * (n-2) * (n-3); // 4 different rows
    
    cout << "Total possible 4x4 combinations to check: " << totalPossible << endl;
    cout << "Checking matrices with all unique elements..." << endl;
    
    ProgressBar progressBar(50, "Checking matrices");
    
    // Try all combinations of 4 different rows
    for (size_t i1 = 0; i1 < validRows.size(); i1++) {
        for (size_t i2 = 0; i2 < validRows.size(); i2++) {
            if (i2 == i1) continue;
            
            for (size_t i3 = 0; i3 < validRows.size(); i3++) {
                if (i3 == i1 || i3 == i2) continue;
                
                for (size_t i4 = 0; i4 < validRows.size(); i4++) {
                    if (i4 == i1 || i4 == i2 || i4 == i3) continue;
                    
                    totalCombinations++;
                    
                    // Check if all 16 elements in the 4x4 matrix are unique
                    set<long> allElements;
                    bool allUnique = true;
                    
                    vector<vector<long>> matrix = {
                        validRows[i1], validRows[i2], validRows[i3], validRows[i4]
                    };
                    
                    for (int row = 0; row < 4; row++) {
                        for (int col = 0; col < 4; col++) {
                            long element = matrix[row][col];
                            if (allElements.count(element)) {
                                allUnique = false;
                                break;
                            }
                            allElements.insert(element);
                        }
                        if (!allUnique) break;
                    }
                    
                    if (allUnique) {
                        validMatrices++;
                        
                        // Create NTL matrix and check determinant
                        Mat<ZZ_p> M;
                        M.SetDims(4, 4);
                        
                        for (int row = 0; row < 4; row++) {
                            for (int col = 0; col < 4; col++) {
                                M[row][col] = ZZ_p(matrix[row][col]);
                            }
                        }
                        
                        ZZ_p det = determinant(M);
                        if (det == 0) {
                            singularCount++;
                        } else {
                            nonsingularCount++;
                        }
                    }
                    
                    // Update progress
                    if (totalCombinations % 10000 == 0) {
                        double progress = (double)totalCombinations / totalPossible;
                        progressBar.update(progress, totalCombinations, totalPossible);
                    }
                }
            }
        }
    }
    
    progressBar.finish();
    
    cout << "Total combinations checked: " << totalCombinations << endl;
    cout << "Valid matrices (all elements unique): " << validMatrices << endl;
}

// Write results to file
void writeResults(long p, const vector<vector<long>>& validRows, 
                 long singularCount, long nonsingularCount, long duration) {
    
    string filename = "matrix_analysis_p" + to_string(p) + ".txt";
    ofstream fout(filename);
    
    if (!fout.is_open()) {
        cerr << "Error creating output file" << endl;
        return;
    }
    
    auto now = chrono::system_clock::now();
    auto time_t = chrono::system_clock::to_time_t(now);
    
    fout << "=== 4x4 MATRIX SINGULARITY ANALYSIS ===" << endl;
    fout << "Generated on: " << put_time(localtime(&time_t), "%Y-%m-%d %H:%M:%S") << endl;
    fout << "Prime p: " << p << endl;
    fout << "Target row sum: " << (p-1) << endl;
    fout << "Matrix size: 4x4" << endl;
    fout << string(50, '=') << endl << endl;
    
    fout << "CONDITIONS:" << endl;
    fout << "1. Each row has 4 unique elements from {1, 2, ..., " << p << "}" << endl;
    fout << "2. Sum of each row = " << (p-1) << endl;
    fout << "3. All 16 elements in matrix are unique" << endl;
    fout << "4. No zeros allowed" << endl;
    fout << string(50, '-') << endl;
    
    fout << "VALID ROWS FOUND: " << validRows.size() << endl;
    fout << "Valid rows (each sums to " << (p-1) << "):" << endl;
    
    for (size_t i = 0; i < validRows.size(); i++) {
        fout << "Row " << setw(3) << (i+1) << ": ";
        long sum = 0;
        for (size_t j = 0; j < validRows[i].size(); j++) {
            fout << setw(2) << validRows[i][j];
            if (j < validRows[i].size() - 1) fout << " ";
            sum += validRows[i][j];
        }
        fout << " (sum=" << sum << ")" << endl;
    }
    
    fout << string(50, '-') << endl;
    fout << "MATRIX ANALYSIS RESULTS:" << endl;
    fout << "Singular matrices: " << singularCount << endl;
    fout << "Non-singular matrices: " << nonsingularCount << endl;
    fout << "Total valid matrices: " << (singularCount + nonsingularCount) << endl;
    
    long total = singularCount + nonsingularCount;
    if (total > 0) {
        double singularPercent = (double)singularCount / total * 100;
        fout << "Singular percentage: " << fixed << setprecision(2) << singularPercent << "%" << endl;
    }
    
    fout << "Computation time: " << duration << " milliseconds" << endl;
    fout << string(50, '=') << endl;
    
    fout.close();
    cout << "Results saved to: " << filename << endl;
}

int main() {
    long p;
    
    cout << "=== 4x4 Matrix Singularity Analysis ===" << endl;
    cout << "Enter prime p: ";
    cin >> p;
    
    // Validate input
    if (p < 5) {
        cerr << "Error: Need p >= 5 to generate 4x4 matrices with unique elements" << endl;
        cerr << "       (Need at least 16 unique values from 1 to p)" << endl;
        return 1;
    }
    
    // Check if target sum p-1 is achievable with 4 unique elements
    long minSum = 1 + 2 + 3 + 4; // = 10
    long maxSum = (p-3) + (p-2) + (p-1) + p; // = 4p - 6
    
    if (p - 1 < minSum || p - 1 > maxSum) {
        cerr << "Error: Target sum " << (p-1) << " not achievable with 4 unique elements from 1-" << p << endl;
        cerr << "       Achievable range: " << minSum << " to " << maxSum << endl;
        return 1;
    }
    
    cout << "Conditions:" << endl;
    cout << "- 4x4 matrices only" << endl;
    cout << "- Each row: 4 unique elements from {1,2,...," << p << "}" << endl;
    cout << "- Each row sum = " << (p-1) << endl;
    cout << "- All 16 matrix elements must be unique" << endl;
    cout << "- No zeros" << endl << endl;
    
    auto start = chrono::high_resolution_clock::now();
    
    // Step 1: Generate all valid rows
    cout << "Step 1: Generating valid rows..." << endl;
    vector<vector<long>> validRows;
    vector<long> currentRow(4);
    vector<bool> used(p + 1, false);
    
    generateValidRows(validRows, currentRow, used, 0, p, 0);
    
    cout << "Found " << validRows.size() << " valid rows (each sums to " << (p-1) << ")" << endl;
    
    if (validRows.empty()) {
        cout << "No valid rows found. Cannot proceed." << endl;
        return 1;
    }
    
    // Step 2: Generate and analyze matrices
    cout << "\nStep 2: Analyzing 4x4 matrix combinations..." << endl;
    long singularCount = 0, nonsingularCount = 0;
    
    generateMatrixCombinations(validRows, p, singularCount, nonsingularCount);
    
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    
    // Results
    cout << "\n=== FINAL RESULTS ===" << endl;
    cout << "Prime p: " << p << endl;
    cout << "Valid rows found: " << validRows.size() << endl;
    cout << "Singular 4x4 matrices: " << singularCount << endl;
    cout << "Non-singular 4x4 matrices: " << nonsingularCount << endl;
    cout << "Total valid 4x4 matrices: " << (singularCount + nonsingularCount) << endl;
    
    long total = singularCount + nonsingularCount;
    if (total > 0) {
        double singularPercent = (double)singularCount / total * 100;
        cout << "Singular percentage: " << fixed << setprecision(2) << singularPercent << "%" << endl;
    }
    
    cout << "Time taken: " << duration << " ms" << endl;
    
    // Write results to file
    writeResults(p, validRows, singularCount, nonsingularCount, duration);
    
    return 0;
}