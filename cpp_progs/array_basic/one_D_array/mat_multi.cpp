#include <iostream>
using namespace std;

int main() {
    int a[2][2], b[2][2], c[2][2] = {0};

    cout << "Enter first 2x2 matrix:\n";
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            cin >> a[i][j];

    cout << "Enter second 2x2 matrix:\n";
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            cin >> b[i][j];

    // Multiplication
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                c[i][j] += a[i][k] * b[k][j];

    cout << "Multiplication Result:\n";
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
