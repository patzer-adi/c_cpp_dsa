#include <iostream>
using namespace std;

int main() {
    int arr[10];
    int sum = 0;

    cout << "Enter 10 numbers:\n";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    cout << "Average = " << (sum / 10.0);
    return 0;
}
