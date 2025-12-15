#include <iostream>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    int length = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        length++;
    }

    cout << "Length of string = " << length;
    return 0;
}
