#include <iostream>
using namespace std;

int main() {
    int N, i = 2;
    cout << "Enter N: ";
    cin >> N;

    while (i <= N) {
        cout << i << " ";
        i += 2;
    }
    return 0;
}
