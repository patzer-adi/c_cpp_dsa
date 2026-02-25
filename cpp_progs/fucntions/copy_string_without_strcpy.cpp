#include <iostream>
using namespace std;

void copyString(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int main() {
    char src[50] = "C++ Programming";
    char dest[50];

    copyString(dest, src);
    cout << dest;

    return 0;
}
