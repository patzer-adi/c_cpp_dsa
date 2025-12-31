#include <iostream>
using namespace std;
int main() {
    int n, i = 2, flag = 0;
    cin >> n;
    while (i <= n / 2) {
        if (n % i == 0) {
            flag = 1;
            break;
        }
        i++;
    }
    if (flag == 0 && n > 1) cout << "Prime";
    else cout << "Composite";
}
