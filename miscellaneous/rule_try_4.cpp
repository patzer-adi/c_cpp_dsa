// Generate matrices using different strategies with unique elements across entire matrix
//version 7


void generateMatrices(const vector<vector<long>>& rows, long m, long p, long n, 
                     const string& strategy = "sequential") {
    ZZ_p::init(p);
    
    string filename = "matrices_" + strategy + "_m" + to_string(m) + "_p" + to_string(p) + ".txt";
    ofstream fout(filename);
    if (!fout.is_open()) {
        cerr << "Error opening " << filename << endl;
        return;
    }
    
    // Write header
    auto now = chrono::system_clock::now();
    auto time_t = chrono::system_clock::to_time_t(now);
    
    fout << "=== MATRIX GENERATION REPORT ===" << endl;
    fout << "Generated on: " << put_time(localtime(&time_t), "%Y-%m-%d %H:%M:%S") << endl;
    fout << "Strategy: " << strategy << endl;
    fout << "Parameters:" << endl;
    fout << "  Matrix order: " << m << " x " << m << endl;
    fout << "  Prime p: " << p << endl;
    fout << "  Available rows: " << rows.size() << endl;
    fout << "  Matrices requested: " << n << endl;
    fout << "  Constraint: ALL elements in matrix must be unique" << endl;
    fout << string(60, '=') << endl << endl;
    
    long singularCount = 0, nonsingularCount = 0;
    long successfulMatrices = 0;
    
    ProgressBar progressBar(50, "Generating matrices");
    
    // Check if it's theoretically possible
    if (m * m > p) {
        cout << "Error: Cannot generate " << m << "x" << m << " matrix with unique elements from 1-" << p << endl;
        cout << "Need " << (m * m) << " unique elements but only " << p << " available." << endl;
        fout << "ERROR: Matrix generation impossible - need " << (m*m) << " unique elements from only " << p << " values" << endl;
        fout.close();
        return;
    }
    
    for (long k = 0; k < n && successfulMatrices < n; k++) {
        bool matrixFound = false;
        Mat<ZZ_p> M;
        M.SetDims(m, m);
        vector<size_t> selectedRows;
        
        // Try different combinations of rows to find one with all unique elements
        if (strategy == "exhaustive_search") {
            // Try all combinations of m rows from available rows
            vector<size_t> rowIndices(rows.size());
            iota(rowIndices.begin(), rowIndices.end(), 0);
            
            // Generate all combinations of m rows
            function<bool(vector<size_t>&, size_t, size_t)> findValidCombination = 
                [&](vector<size_t>& combination, size_t start, size_t depth) -> bool {
                if (depth == m) {
                    // Check if this combination gives all unique elements
                    set<long> allElements;
                    bool valid = true;
                    
                    for (size_t i = 0; i < m && valid; i++) {
                        for (size_t j = 0; j < m && valid; j++) {
                            long element = rows[combination[i]][j];
                            if (allElements.count(element)) {
                                valid = false; // Duplicate found
                            } else {
                                allElements.insert(#include <NTL/ZZ_p.h>
#include <NTL/mat_ZZ_p.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <random>
#include <iomanip>
#include <set>
using namespace std;
using namespace NTL;

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

// Recursively generate rows of length m from 1..p with sum = target and unique elements
void generateRowsHelper(vector<vector<long>>& rows, vector<long>& current, 
                       vector<bool>& used, long idx, long m, long p, long target, long currentSum) {
    // Pruning: if we can't reach target even with remaining unused values
    if (idx == m) {
        if (currentSum == target) {
            rows.push_back(current);
        }
        return;
    }
    
    long remaining = m - idx;
    
    // Calculate min and max possible sums with remaining positions
    vector<long> availableVals;
    for (long val = 1; val <= p; val++) {
        if (!used[val]) {
            availableVals.push_back(val);
        }
    }
    
    // If we don't have enough unused values, return
    if (availableVals.size() < remaining) {
        return;
    }
    
    // Sort available values to calculate bounds
    sort(availableVals.begin(), availableVals.end());
    
    // Calculate minimum possible sum (using smallest available values)
    long minPossible = currentSum;
    for (long i = 0; i < remaining && i < availableVals.size(); i++) {
        minPossible += availableVals[i];
    }
    
    // Calculate maximum possible sum (using largest available values)
    long maxPossible = currentSum;
    long startIdx = max(0L, (long)availableVals.size() - remaining);
    for (long i = startIdx; i < availableVals.size(); i++) {
        maxPossible += availableVals[i];
    }
    
    if (maxPossible < target || minPossible > target) {
        return;
    }
    
    // Try each unused value
    for (long val = 1; val <= p; val++) {
        if (!used[val]) {
            current[idx] = val;
            used[val] = true;
            generateRowsHelper(rows, current, used, idx + 1, m, p, target, currentSum + val);
            used[val] = false; // backtrack
        }
    }
}

// Generate all unique rows with given sum and unique elements
vector<vector<long>> generateRows(long m, long p, long targetSum) {
    vector<vector<long>> rows;
    vector<long> current(m, 1);
    vector<bool> used(p + 1, false); // used[i] = true if value i is used in current row
    
    cout << "Generating rows of length " << m << " with UNIQUE elements 1-" << p 
         << " and sum = " << targetSum << "..." << endl;
    
    // Check if it's even possible to generate such rows
    if (m > p) {
        cout << "Error: Cannot generate rows of length " << m 
             << " with unique elements from 1-" << p << endl;
        return rows;
    }
    
    // Check if target sum is achievable with unique elements
    long minSum = m * (m + 1) / 2; // sum of 1,2,3,...,m
    long maxSum = m * (2 * p - m + 1) / 2; // sum of largest m values: (p-m+1),...,p
    
    if (targetSum < minSum || targetSum > maxSum) {
        cout << "Error: Target sum " << targetSum << " is not achievable." << endl;
        cout << "With " << m << " unique elements from 1-" << p 
             << ", sum must be between " << minSum << " and " << maxSum << endl;
        return rows;
    }
    
    generateRowsHelper(rows, current, used, 0, m, p, targetSum, 0);
    
    // Remove duplicates (though this algorithm shouldn't generate duplicates)
    sort(rows.begin(), rows.end());
    rows.erase(unique(rows.begin(), rows.end()), rows.end());
    
    return rows;
}

// Write rows to file with better formatting
void writeRowsToFile(const vector<vector<long>>& rows, const string& filename, 
                    long m, long p, long targetSum) {
    ofstream fout(filename);
    if (!fout.is_open()) {
        cerr << "Error writing to " << filename << endl;
        return;
    }
    
    fout << "=== ROW GENERATION REPORT ===" << endl;
    fout << "Parameters:" << endl;
    fout << "  Row length (m): " << m << endl;
    fout << "  Element range: 1 to " << p << " (UNIQUE elements per row)" << endl;
    fout << "  Target sum: " << targetSum << endl;
    fout << "  Total valid rows: " << rows.size() << endl;
    fout << string(40, '=') << endl << endl;
    
    for (size_t i = 0; i < rows.size(); ++i) {
        fout << "Row " << setw(6) << (i + 1) << ": ";
        long sum = 0;
        for (size_t j = 0; j < rows[i].size(); ++j) {
            fout << setw(3) << rows[i][j];
            if (j < rows[i].size() - 1) fout << " ";
            sum += rows[i][j];
        }
        fout << " (sum=" << sum << ")" << endl;
    }
    fout.close();
}

// Check if we have enough rows to form n matrices
bool validateMatrixGeneration(long availableRows, long m, long n) {
    long matricesWeCanMake = availableRows / m;
    if (matricesWeCanMake < n) {
        cout << "Warning: Can only generate " << matricesWeCanMake 
             << " matrices from " << availableRows << " rows (need " 
             << m << " rows per matrix)" << endl;
        return false;
    }
    return true;
}

// Generate matrices using different strategies
void generateMatrices(const vector<vector<long>>& rows, long m, long p, long n, 
                     const string& strategy = "sequential") {
    ZZ_p::init(p);
    
    string filename = "matrices_" + strategy + "_m" + to_string(m) + "_p" + to_string(p) + ".txt";
    ofstream fout(filename);
    if (!fout.is_open()) {
        cerr << "Error opening " << filename << endl;
        return;
    }
    
    // Write header
    auto now = chrono::system_clock::now();
    auto time_t = chrono::system_clock::to_time_t(now);
    
    fout << "=== MATRIX GENERATION REPORT ===" << endl;
    fout << "Generated on: " << put_time(localtime(&time_t), "%Y-%m-%d %H:%M:%S") << endl;
    fout << "Strategy: " << strategy << endl;
    fout << "Parameters:" << endl;
    fout << "  Matrix order: " << m << " x " << m << endl;
    fout << "  Prime p: " << p << endl;
    fout << "  Available rows: " << rows.size() << endl;
    fout << "  Matrices requested: " << n << endl;
    fout << string(50, '=') << endl << endl;
    
    long singularCount = 0, nonsingularCount = 0;
    long maxMatrices = min(n, (long)(rows.size() / m));
    
    ProgressBar progressBar(50, "Generating matrices");
    
    // Prepare row selection based on strategy
    vector<size_t> rowIndices(rows.size());
    iota(rowIndices.begin(), rowIndices.end(), 0);
    
    if (strategy == "random") {
        random_device rd;
        mt19937 g(rd());
        shuffle(rowIndices.begin(), rowIndices.end(), g);
    }
    
    for (long k = 0; k < maxMatrices; k++) {
        Mat<ZZ_p> M;
        M.SetDims(m, m);
        
        // Fill matrix with rows based on strategy
        for (long i = 0; i < m; i++) {
            size_t rowIndex;
            if (strategy == "sequential") {
                rowIndex = k * m + i;
            } else if (strategy == "random") {
                rowIndex = rowIndices[k * m + i];
            } else { // cyclical
                rowIndex = ((k * m + i) % rows.size());
            }
            
            for (long j = 0; j < m; j++) {
                M[i][j] = ZZ_p(rows[rowIndex][j]);
            }
        }
        
        ZZ_p det = determinant(M);
        bool singular = (det == 0);
        
        if (singular) {
            singularCount++;
        } else {
            nonsingularCount++;
        }
        
        // Write matrix info
        fout << "Matrix #" << (k + 1) << " (" << (singular ? "Singular" : "Nonsingular") << "):" << endl;
        for (long i = 0; i < m; i++) {
            for (long j = 0; j < m; j++) {
                fout << setw(4) << M[i][j];
                if (j < m - 1) fout << " ";
            }
            fout << endl;
        }
        fout << "Determinant: " << det << endl;
        
        // Show which rows were used
        fout << "Rows used: ";
        for (long i = 0; i < m; i++) {
            size_t rowIndex;
            if (strategy == "sequential") {
                rowIndex = k * m + i;
            } else if (strategy == "random") {
                rowIndex = rowIndices[k * m + i];
            } else {
                rowIndex = ((k * m + i) % rows.size());
            }
            fout << (rowIndex + 1);
            if (i < m - 1) fout << ", ";
        }
        fout << endl;
        fout << string(50, '-') << endl;
        
        // Update progress
        double progress = (double)(k + 1) / maxMatrices;
        progressBar.update(progress, k + 1, maxMatrices);
    }
    
    progressBar.finish();
    
    // Write summary
    fout << endl << string(50, '=') << endl;
    fout << "=== SUMMARY ===" << endl;
    fout << "Matrices generated: " << maxMatrices << endl;
    fout << "Singular matrices: " << singularCount << endl;
    fout << "Nonsingular matrices: " << nonsingularCount << endl;
    
    if (maxMatrices > 0) {
        double singularPercent = (double)singularCount / maxMatrices * 100;
        fout << "Singular percentage: " << fixed << setprecision(2) << singularPercent << "%" << endl;
    }
    fout << string(50, '=') << endl;
    
    fout.close();
    
    cout << "Results saved to: " << filename << endl;
    cout << "Singular: " << singularCount << ", Nonsingular: " << nonsingularCount << endl;
}

int main() {
    long p, m, n, targetSum;
    string strategy;
    
    cout << "=== Matrix Generator with Unique Row Elements ===" << endl;
    cout << "Enter prime p: ";
    cin >> p;
    
    cout << "Enter matrix order m: ";
    cin >> m;
    
    cout << "Enter target sum for each row (default " << (p-1) << "): ";
    cin >> targetSum;
    
    cout << "Enter number of matrices n: ";
    cin >> n;
    
    cout << "Enter generation strategy (sequential/random/cyclical) [default: sequential]: ";
    cin >> strategy;
    if (strategy.empty()) strategy = "sequential";
    
    // Validation
    if (p <= 1 || m <= 0 || n <= 0) {
        cerr << "Error: Invalid parameters" << endl;
        return 1;
    }
    
    if (m > p) {
        cerr << "Error: Cannot generate rows of length " << m 
             << " with unique elements from 1 to " << p << endl;
        return 1;
    }
    
    // Check if target sum is achievable with unique elements
    long minSum = m * (m + 1) / 2; // sum of 1,2,3,...,m
    long maxSum = m * (2 * p - m + 1) / 2; // sum of largest m values
    
    if (targetSum < minSum || targetSum > maxSum) {
        cerr << "Error: Target sum " << targetSum << " is not achievable." << endl;
        cerr << "With " << m << " unique elements from 1-" << p 
             << ", sum must be between " << minSum << " and " << maxSum << endl;
        return 1;
    }
    
    auto start = chrono::high_resolution_clock::now();
    
    // Step 1: Generate rows
    vector<vector<long>> rows = generateRows(m, p, targetSum);
    cout << "Generated " << rows.size() << " valid rows." << endl;
    
    if (rows.empty()) {
        cout << "No valid rows found with the given constraints." << endl;
        return 1;
    }
    
    // Write rows to file
    writeRowsToFile(rows, "rows_m" + to_string(m) + "_p" + to_string(p) + 
                   "_sum" + to_string(targetSum) + ".txt", m, p, targetSum);
    
    // Step 2: Validate matrix generation
    if (!validateMatrixGeneration(rows.size(), m, n)) {
        char choice;
        cout << "Continue with available matrices? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            return 0;
        }
    }
    
    // Step 3: Generate matrices
    generateMatrices(rows, m, p, n, strategy);
    
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    
    cout << "Computation finished in " << duration << " ms" << endl;
    
    // Write timing information
    ofstream tfile("timing_report.txt");
    if (tfile.is_open()) {
        tfile << "=== TIMING REPORT ===" << endl;
        tfile << "Parameters: m=" << m << ", p=" << p << ", sum=" << targetSum 
              << ", n=" << n << endl;
        tfile << "Rows generated: " << rows.size() << endl;
        tfile << "Time taken: " << duration << " ms" << endl;
        tfile << "Strategy: " << strategy << endl;
        tfile.close();
    }
    
    return 0;
}