#include <iostream>
using namespace std;

int main() {
    int a[2][2];

    cout << "Enter a 2x2 matrix:\n";
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cin >> a[i][j];
        }
    }

    cout << "Matrix:\n";
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
