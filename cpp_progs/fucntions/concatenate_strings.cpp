#include <iostream>
#include <cstring>
using namespace std;

void concatenate(char s1[], char s2[]) {
    strcat(s1, s2);
}

int main() {
    char s1[50] = "Hello ";
    char s2[50] = "World";

    concatenate(s1, s2);
    cout << s1;

    return 0;
}
