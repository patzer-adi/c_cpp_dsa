#include <iostream>
#include <cstring>
using namespace std;

void concatenate(char str1[], char str2[]) {
    strcat(str1, str2);
}

int main() {
    char str1[50] = "Hello ";
    char str2[50] = "C++";

    concatenate(str1, str2);
    cout << "Concatenated String: " << str1;

    return 0;
}
