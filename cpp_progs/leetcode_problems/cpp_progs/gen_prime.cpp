#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

bool is_prime(long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    for (long i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

int main() {
    long start = 17;
    long end = 541; // you can increase this to generate more primes

    cout << "Generating primes between " << start << " and " << end << "...\n";

    ofstream fout("primes.txt");
    if (!fout) {
        cerr << "Error: Could not open primes.txt for writing\n";
        return 1;
    }

    for (long i = start; i <= end; i++) {
        if (is_prime(i)) {
            fout << i << "\n";
        }
    }

    fout.close();
    cout << "✅ primes.txt generated successfully.\n";
    return 0;
}
