#include <iostream>
using namespace std;

int main() {
    int num;
    int sumEven = 0;
    long long productOdd = 1;
    bool foundOdd = false;

    cout << "Enter 10 integers:\n";
    for (int i = 0; i < 10; i++) {
        cin >> num;

        if (num % 2 == 0)
            sumEven += num;
        else {
            productOdd *= num;
            foundOdd = true;
        }
    }

    cout << "Sum of even numbers = " << sumEven << endl;

    if (foundOdd)
        cout << "Product of odd numbers = " << productOdd;
    else
        cout << "No odd numbers entered.";

    return 0;
}
