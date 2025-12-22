#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    do {
        cout << N << " ";
        N--;
    } while (N >= 1);

    return 0;
}
