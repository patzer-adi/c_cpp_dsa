#include <iostream>
using namespace std;

int main() {
    int M,N;
    cout<<"Enter rows and columns: ";
    cin>>M>>N;

    int **a=new int*[M];
    for(int i=0;i<M;i++) a[i]=new int[N];

    cout<<"Enter elements:\n";
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            cin>>a[i][j];

    int r,c;
    cout<<"Enter position (row column): ";
    cin>>r>>c;

    cout<<"Element = "<<a[r][c];

    for(int i=0;i<M;i++) delete[] a[i];
    delete[] a;
    return 0;
}
