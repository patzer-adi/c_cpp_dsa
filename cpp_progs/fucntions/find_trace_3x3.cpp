#include <iostream>
using namespace std;

int trace(int mat[3][3]) {
    int t = 0;
    for (int i = 0; i < 3; i++)
        t += mat[i][i];
    return t;
}

int main() {
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Trace = " << trace(mat);
    return 0;
}
