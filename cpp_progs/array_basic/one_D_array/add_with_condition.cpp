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
        sum /= 2;
    else
        sum /= 3;

    cout << "Result = " << sum;
    return 0;
}
