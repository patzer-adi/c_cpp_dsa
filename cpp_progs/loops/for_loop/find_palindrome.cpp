#include <iostream>
using namespace std;

int main() {
    int n, temp, rev = 0;
    cout << "Enter a number: ";
    cin >> n;

    temp = n;

    while (temp != 0) {
        rev = rev * 10 + (temp % 10);
        temp /= 10;
    }

    if (rev == n)
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}
