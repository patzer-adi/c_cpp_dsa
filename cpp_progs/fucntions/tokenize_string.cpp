#include <iostream>
#include <cstring>
using namespace std;

void tokenize(char str[]) {
    char *token = strtok(str, " ");
    while (token != NULL) {
        cout << token << endl;
        token = strtok(NULL, " ");
    }
}

int main() {
    char str[100] = "C plus plus programming";

    tokenize(str);

    return 0;
}
