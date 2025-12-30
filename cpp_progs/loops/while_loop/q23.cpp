#include <iostream>
using namespace std;
int main() {
    int a[10], i = 0;
    float sum = 0;
    while (i < 10) {
        cin >> a[i];
        sum += a[i];
        i++;
    }
    cout << sum / 10;
}
