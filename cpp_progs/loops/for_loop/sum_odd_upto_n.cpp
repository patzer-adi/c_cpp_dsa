#include <iostream>
using namespace std;

int main() {
    int N, sum = 0;
    cout << "Enter N: ";
    cin >> N;

    for (int i = 1; i <= N; i += 2) {
        sum += i;
    }

    cout << "Sum of odd numbers: " << sum;
    return 0;
}
