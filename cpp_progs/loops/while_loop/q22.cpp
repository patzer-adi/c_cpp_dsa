#include <iostream>
using namespace std;
int main() {
    int a[10], i = 0;
    while (i < 10) {
        cin >> a[i];
        i++;
    }
    int max = a[0];
    i = 1;
    while (i < 10) {
        if (a[i] > max) max = a[i];
        i++;
    }
    cout << max;
}
