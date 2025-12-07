#include <iostream>
using namespace std;

int main() {
    int arr[5];

    cout << "Enter 10 integers: ";
    for(int i = 0; i < 10; i++) {
        cin >> arr[i];  // ❌ Exceeds array boundary!
    }

    cout << "Stored values: ";
    for(int i = 0; i < 10; i++) {
        cout << arr[i] << " ";  // ❌ Reading outside array!
    }

    return 0;
}
