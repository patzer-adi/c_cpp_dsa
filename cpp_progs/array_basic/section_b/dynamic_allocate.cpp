#include <iostream>
using namespace std;

int main() {
    int M, N;
    cout << "Enter rows (M) and columns (N): ";
    cin >> M >> N;

    int **arr = new int*[M];
    for(int i=0;i<M;i++)
        arr[i] = new int[N];

    cout << "Enter elements:\n";
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            cin >> arr[i][j];

    cout << "Matrix:\n";
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    for(int i=0;i<M;i++) delete[] arr[i];
    delete[] arr;
    return 0;
}
