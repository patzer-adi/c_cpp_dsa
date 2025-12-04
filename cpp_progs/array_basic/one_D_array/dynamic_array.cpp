#include <iostream>
using namespace std;

int main() {
    int *arr = new int[10];

    cout << "Enter 10 numbers:\n";
    for(int i=0; i<10; i++)
        cin >> arr[i];

    cout << "You entered:\n";
    for(int i=0; i<10; i++)
        cout << arr[i] << " ";

    delete[] arr; // free memory
    return 0;
}
