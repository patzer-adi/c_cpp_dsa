#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;

    cout << "Enter a sentence: ";
    getline(cin, line);

    cout << "You entered: " << line;
    return 0;
}
