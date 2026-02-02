#include <iostream>
#include <cstring>
using namespace std;

void copyString(char dest[], char src[]) {
    strcpy(dest, src);
}

int main() {
    char str1[50] = "Hello World";
    char str2[50];

    copyString(str2, str1);
    cout << "Copied String: " << str2;

    return 0;
}
