#include <NTL/ZZ_p.h>
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

// Strategy 1: Generate rows with different target sums
void generateRowsWithVariedSums(vector<vector<long>>& allRows, long m, long p, 
                               vector<long>& targetSums) {
    for (long targetSum : targetSums) {
        vector<vector<long>> rows;
        vector<long> current(m, 1);
        vector<bool> used(p + 1, false);
        
        // Check if sum is achievable
        long minSum = m * (m + 1) / 2;
        long maxSum = m * (2 * p - m + 1) / 2;
        
        if (targetSum >= minSum && targetSum <= maxSum) {
            generateRowsHelper(rows, current, used, 0, m, p, targetSum, 0);
            allRows.insert(allRows.end(), rows.begin(), rows.end());
        }
    }
}

void generateRowsHelper(vector<vector<long>>& rows, vector<long>& current, 
                       vector<bool>& used, long idx, long m, long p, long target, long currentSum) {
    if (idx == m) {
        if (currentSum == target) {
            rows.push_back(current);
        }
        return;
    }
    
    long remaining = m - idx;
    
    vector<long> availableVals;
    for (long val = 1; val <= p; val++) {
        if (!used[val]) {
            availableVals.push_back(val);
        }
    }
    
    if (availableVals.size() < remaining) {
        return;
    }
    
    sort(availableVals.begin(), availableVals.end());
    
    long minPossible = currentSum;
    for (long i = 0; i < remaining && i < availableVals.size(); i++) {
        minPossible += availableVals[i];
    }
    
    long maxPossible = currentSum;
    long startIdx = max(0L, (long)availableVals.size() - remaining);
    for (long i = startIdx; i < availableVals.size(); i++) {
        maxPossible += availableVals[i];
    }
    
    if (maxPossible < target || minPossible > target) {
        return;
    }
    
    for (long val = 1; val <= p; val++) {
        if (!used[val]) {
            current[idx] = val;
            used[val] = true;
            generateRowsHelper(rows, current, used, idx + 1, m, p, target, currentSum + val);
            used[val] = false;
        }
    }
}

// Strategy 2: Generate completely random matrices with unique elements
Mat<ZZ_p> generateRandomUniqueMatrix(long m, long p) {
    if (m * m > p) {
        throw runtime_error("Not enough unique elements for matrix");
    }
    
    vector<long> pool(p);
    iota(pool.begin(), pool.end(), 1);
    
    random_device rd;
    mt19937 g(rd());
    shuffle(pool.begin(), pool.end(), g);
    
    Mat<ZZ_p> M;
    M.SetDims(m, m);
    long idx = 0;
    
    for (long i = 0; i < m; i++) {
        for (long j = 0; j < m; j++) {
            M[i][j] = ZZ_p(pool[idx++]);
        }
    }
    
    return M;
}

// Strategy 3: Generate diagonal dominant matrices
Mat<ZZ_p> generateDiagonalDominantMatrix(long m, long p) {
    Mat<ZZ_p> M;
    M.SetDims(m, m);
    random_device rd;
    mt19937 g(rd());
    uniform_int_distribution<long> dis(1, p);
    
    for (long i = 0; i < m; i++) {
        long rowSum = 0;
        for (long j = 0; j < m; j++) {
            if (i != j) {
                M[i][j] = ZZ_p(dis(g));
                rowSum += conv<long>(M[i][j]);
            }
        }
        // Make diagonal element larger than sum of other elements in row
        long diagonalVal = rowSum + dis(g) + 1;
        if (diagonalVal > p) diagonalVal = p; // Cap at p
        M[i][i] = ZZ_p(diagonalVal);
    }
    
    return M;
}

// Strategy 4: Generate matrices and filter out singular ones
vector<Mat<ZZ_p>> generateNonSingularMatrices(long m, long p, long targetCount, 
                                            const string& strategy) {
    vector<Mat<ZZ_p>> nonSingularMatrices;
    const long MAX_ATTEMPTS = targetCount * 100; // Try up to 100x more than needed
    long attempts = 0;
    
    ProgressBar progressBar(50, "Searching for non-singular matrices");
    
    while (nonSingularMatrices.size() < targetCount && attempts < MAX_ATTEMPTS) {
        try {
            Mat<ZZ_p> M;
            
            if (strategy == "random_unique") {
                M = generateRandomUniqueMatrix(m, p);
            } else if (strategy == "diagonal_dominant") {
                M = generateDiagonalDominantMatrix(m, p);
            } else { // random_general
                M.SetDims(m, m);
                random_device rd;
                mt19937 g(rd());
                uniform_int_distribution<long> dis(1, p);
                
                for (long i = 0; i < m; i++) {
                    for (long j = 0; j < m; j++) {
                        M[i][j] = ZZ_p(dis(g));
                    }
                }
            }
            
            ZZ_p det = determinant(M);
            if (det != 0) {
                nonSingularMatrices.push_back(M);
            }
            
            attempts++;
            
            // Update progress based on successful finds
            double progress = (double)nonSingularMatrices.size() / targetCount;
            progressBar.update(progress, nonSingularMatrices.size(), targetCount);
            
        } catch (const exception& e) {
            attempts++;
        }
    }
    
    progressBar.finish();
    
    if (nonSingularMatrices.size() < targetCount) {
        cout << "Warning: Only found " << nonSingularMatrices.size() 
             << " non-singular matrices out of " << targetCount << " requested" << endl;
        cout << "Tried " << attempts << " attempts total" << endl;
    }
    
    return nonSingularMatrices;
}

// Strategy 5: Varied row sums approach
vector<Mat<ZZ_p>> generateVariedSumMatrices(const vector<vector<long>>& allRows, 
                                           long m, long targetCount) {
    vector<Mat<ZZ_p>> matrices;
    random_device rd;
    mt19937 g(rd());
    
    const long MAX_ATTEMPTS = targetCount * 50;
    long attempts = 0;
    
    ProgressBar progressBar(50, "Generating matrices with varied row sums");
    
    while (matrices.size() < targetCount && attempts < MAX_ATTEMPTS) {
        Mat<ZZ_p> M;
        M.SetDims(m, m);
        
        // Randomly select m different rows
        vector<size_t> indices(allRows.size());
        iota(indices.begin(), indices.end(), 0);
        shuffle(indices.begin(), indices.end(), g);
        
        if (indices.size() >= m) {
            for (long i = 0; i < m; i++) {
                for (long j = 0; j < m; j++) {
                    M[i][j] = ZZ_p(allRows[indices[i]][j]);
                }
            }
            
            ZZ_p det = determinant(M);
            if (det != 0) {
                matrices.push_back(M);
            }
        }
        
        attempts++;
        double progress = (double)matrices.size() / targetCount;
        progressBar.update(progress, matrices.size(), targetCount);
    }
    
    progressBar.finish();
    return matrices;
}

void writeMatricesToFile(const vector<Mat<ZZ_p>>& matrices, const string& filename,
                        const string& strategy, long m, long p) {
    ofstream fout(filename);
    if (!fout.is_open()) {
        cerr << "Error opening " << filename << endl;
        return;
    }
    
    auto now = chrono::system_clock::now();
    auto time_t = chrono::system_clock::to_time_t(now);
    
    fout << "=== NON-SINGULAR MATRIX GENERATION REPORT ===" << endl;
    fout << "Generated on: " << put_time(localtime(&time_t), "%Y-%m-%d %H:%M:%S") << endl;
    fout << "Strategy: " << strategy << endl;
    fout << "Parameters:" << endl;
    fout << "  Matrix order: " << m << " x " << m << endl;
    fout << "  Prime p: " << p << endl;
    fout << "  Generated matrices: " << matrices.size() << endl;
    fout << "  All matrices are NON-SINGULAR (det ≠ 0)" << endl;
    fout << string(60, '=') << endl << endl;
    
    for (size_t k = 0; k < matrices.size(); ++k) {
        ZZ_p det = determinant(matrices[k]);
        
        fout << "Matrix #" << (k + 1) << " (Determinant: " << det << "):" << endl;
        for (long i = 0; i < m; i++) {
            for (long j = 0; j < m; j++) {
                fout << setw(4) << matrices[k][i][j];
                if (j < m - 1) fout << " ";
            }
            fout << endl;
        }
        
        // Calculate row sums to show variety
        fout << "Row sums: ";
        for (long i = 0; i < m; i++) {
            long sum = 0;
            for (long j = 0; j < m; j++) {
                sum += conv<long>(matrices[k][i][j]);
            }
            fout << sum;
            if (i < m - 1) fout << ", ";
        }
        fout << endl;
        fout << string(50, '-') << endl;
    }
    
    fout << endl << "=== SUMMARY ===" << endl;
    fout << "Total non-singular matrices: " << matrices.size() << endl;
    fout << "Success rate: 100% (all generated matrices are non-singular)" << endl;
    fout.close();
}

int main() {
    long p, m, n;
    string strategy;
    
    cout << "=== Non-Singular Matrix Generator ===" << endl;
    cout << "Available strategies:" << endl;
    cout << "1. random_general - Random matrices (allows duplicates)" << endl;
    cout << "2. random_unique - Random matrices with unique elements" << endl;
    cout << "3. diagonal_dominant - Diagonal dominant matrices" << endl;
    cout << "4. varied_sums - Rows with different sums (unique elements)" << endl;
    cout << endl;
    
    cout << "Enter prime p: ";
    cin >> p;
    cout << "Enter matrix order m: ";
    cin >> m;
    cout << "Enter number of NON-SINGULAR matrices needed: ";
    cin >> n;
    cout << "Enter strategy (random_general/random_unique/diagonal_dominant/varied_sums): ";
    cin >> strategy;
    
    if (p <= 1 || m <= 0 || n <= 0) {
        cerr << "Error: Invalid parameters" << endl;
        return 1;
    }
    
    ZZ_p::init(p);
    
    auto start = chrono::high_resolution_clock::now();
    vector<Mat<ZZ_p>> nonSingularMatrices;
    
    if (strategy == "varied_sums") {
        cout << "\nGenerating rows with varied sums..." << endl;
        
        // Generate target sums around the middle range
        long minSum = m * (m + 1) / 2;
        long maxSum = m * (2 * p - m + 1) / 2;
        vector<long> targetSums;
        
        // Create a range of different target sums
        for (long sum = minSum; sum <= maxSum; sum += max(1L, (maxSum - minSum) / 10)) {
            targetSums.push_back(sum);
        }
        
        if (targetSums.size() < 5) {
            // If range is small, use all possible sums
            for (long sum = minSum; sum <= maxSum; sum++) {
                targetSums.push_back(sum);
            }
        }
        
        vector<vector<long>> allRows;
        generateRowsWithVariedSums(allRows, m, p, targetSums);
        
        cout << "Generated " << allRows.size() << " rows with varied sums." << endl;
        
        if (allRows.size() >= m) {
            nonSingularMatrices = generateVariedSumMatrices(allRows, m, n);
        } else {
            cout << "Not enough rows generated. Falling back to random_general strategy." << endl;
            nonSingularMatrices = generateNonSingularMatrices(m, p, n, "random_general");
        }
    } else {
        nonSingularMatrices = generateNonSingularMatrices(m, p, n, strategy);
    }
    
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    
    cout << "\nSuccessfully generated " << nonSingularMatrices.size() 
         << " non-singular matrices!" << endl;
    
    // Write results to file
    string filename = "nonsingular_matrices_" + strategy + "_m" + to_string(m) + 
                     "_p" + to_string(p) + ".txt";
    writeMatricesToFile(nonSingularMatrices, filename, strategy, m, p);
    
    cout << "Results saved to: " << filename << endl;
    cout << "Generation time: " << duration << " ms" << endl;
    
    // Write timing report
    ofstream tfile("nonsingular_timing.txt");
    if (tfile.is_open()) {
        tfile << "=== NON-SINGULAR MATRIX TIMING REPORT ===" << endl;
        tfile << "Strategy: " << strategy << endl;
        tfile << "Parameters: m=" << m << ", p=" << p << ", n=" << n << endl;
        tfile << "Matrices generated: " << nonSingularMatrices.size() << endl;
        tfile << "Time taken: " << duration << " ms" << endl;
        double rate = (double)nonSingularMatrices.size() / (duration / 1000.0);
        tfile << "Generation rate: " << fixed << setprecision(2) << rate << " matrices/second" << endl;
        tfile.close();
    }
    
    return 0;
}