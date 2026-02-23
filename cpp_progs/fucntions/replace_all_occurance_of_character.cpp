#include <iostream>
using namespace std;

void replaceChar(char str[], char oldChar, char newChar) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == oldChar) {
            str[i] = newChar;
        }
    }
}

int main() {
    char str[50] = "banana";

    replaceChar(str, 'a', 'o');
    cout << "Updated String: " << str;

    return 0;
}
