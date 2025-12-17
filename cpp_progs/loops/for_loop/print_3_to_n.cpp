#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    for (int i = 3; i <= N; i += 3) {
        cout << i << " ";
    }

    return 0;
}
