#include <iostream>
using namespace std;

int main() {
    int arr[10];

    cout << "Enter 10 integers:\n";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    cout << "You entered:\n";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nSize of array = " << sizeof(arr) / sizeof(arr[0]);

    return 0;
}
