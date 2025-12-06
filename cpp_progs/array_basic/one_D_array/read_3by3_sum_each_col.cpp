#include <iostream>
using namespace std;

int main() {
    int a[3][3];

    cout << "Enter a 3x3 matrix:\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> a[i][j];
        }
    }

    cout << "Row sums:\n";
    for(int i=0;i<3;i++){
        int sum = 0;
        for(int j=0;j<3;j++){
            sum += a[i][j];
        }
        cout << "Row " << i+1 << ": " << sum << endl;
    }

    cout << "Column sums:\n";
    for(int j=0;j<3;j++){
        int sum = 0;
        for(int i=0;i<3;i++){
            sum += a[i][j];
        }
        cout << "Column " << j+1 << ": " << sum << endl;
    }

    return 0;
}
