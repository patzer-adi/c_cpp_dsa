#include <iostream>
using namespace std;

int main() {
    int N, i = 2;
    cout << "Enter N: ";
    cin >> N;

    do {
        cout << i << " ";
        i += 2;
    } while (i <= N);

    return 0;
}
