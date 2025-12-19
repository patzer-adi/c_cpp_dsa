#include <iostream>
using namespace std;

int main() {
    int arr[5];
    int sum = 0;
    long long product = 1;

    cout << "Enter 5 integers:\n";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
        sum += arr[i];
        product *= arr[i];
    }

    cout << "Sum = " << sum << endl;
    cout << "Product = " << product << endl;

    return 0;
}