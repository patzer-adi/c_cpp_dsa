#include <iostream>
using namespace std;
int main() {
    int x, i = 0, sum = 0;
    while (i < 10) {
        cin >> x;
        if (x % 2 == 0) sum += x;
        i++;
    }
    cout << sum;
}
