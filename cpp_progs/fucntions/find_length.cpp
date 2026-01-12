#include <iostream>
#include <cstring>
using namespace std;

int stringLength(char str[]) {
    return strlen(str);
}

int main() {
    char str[50] = "Programming";

    cout << "Length of string: " << stringLength(str);

    return 0;
}
