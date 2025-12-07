#include <iostream>
using namespace std;

int main() {
    int arr[5], sum = 0;

    cout << "Enter five integers: ";
    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    if(sum > 10)
        cout << "Result = " << sum / 2;
    else
        cout << "Result = " << sum / 3;

    return 0;
}
