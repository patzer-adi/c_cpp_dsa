#include <iostream>
#include <cstring>
using namespace std;

void compareStrings(char str1[], char str2[]) {
    if (strcmp(str1, str2) == 0)
        cout << "Strings are equal";
    else
        cout << "Strings are not equal";
}

int main() {
    char str1[50] = "Hello";
    char str2[50] = "Hello";

    compareStrings(str1, str2);

    return 0;
}
