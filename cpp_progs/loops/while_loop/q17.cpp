#include <iostream>
using namespace std;
int main() {
    int a[10], i = 0;
    while (i < 10) {
        cin >> a[i];
        i++;
    }
    i = 0;
    while (i < 10) {
        cout << a[i] << " ";
        i++;
    }
    cout << "\nSize: 10";
}
