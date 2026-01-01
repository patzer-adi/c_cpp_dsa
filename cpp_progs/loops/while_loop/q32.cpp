#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    int i = 0, count = 0;
    while (s[i] != '\0') {
        count++;
        i++;
    }
    cout << count;
}
