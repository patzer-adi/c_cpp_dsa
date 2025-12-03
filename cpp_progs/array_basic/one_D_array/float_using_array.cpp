#include <iostream>
using namespace std;

int main() {
    float arr[5];

    cout << "Enter five floating numbers: ";
    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    cout << "You entered: ";
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
