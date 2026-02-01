#include <iostream>
#include <cstring>
using namespace std;

void replaceSubstring(char str[], char oldSub[], char newSub[]) {
    char buffer[100];
    char *pos = strstr(str, oldSub);

    if (pos != NULL) {
        int index = pos - str;
        strncpy(buffer, str, index);
        buffer[index] = '\0';
        strcat(buffer, newSub);
        strcat(buffer, pos + strlen(oldSub));
        strcpy(str, buffer);
    }
}

int main() {
    char str[100] = "I love C++";

    replaceSubstring(str, "C++", "Programming");
    cout << "Updated String: " << str;

    return 0;
}
