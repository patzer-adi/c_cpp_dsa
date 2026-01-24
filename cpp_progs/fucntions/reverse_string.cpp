#include <iostream>
#include <cstring>
using namespace std;

void reverseString(char str[]) {
    strrev(str);   // Works in Turbo C++ / MSVC
}

int main() {
    char str[50] = "Hello";

    reverseString(str);
    cout << "Reversed String: " << str;

    return 0;
}
