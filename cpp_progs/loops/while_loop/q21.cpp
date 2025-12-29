#include <iostream>
using namespace std;
int main() {
    int x, y, i = 1, result = 1;
    cin >> x >> y;
    while (i <= y) {
        result *= x;
        i++;
    }
    cout << result;
}
