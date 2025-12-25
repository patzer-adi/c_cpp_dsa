#include <iostream>
using namespace std;
int main() {
    int n, i = 1;
    cin >> n;
    while (i <= n) {
        cout << i << " " << i*i << " " << i*i*i << endl;
        i++;
    }
}
