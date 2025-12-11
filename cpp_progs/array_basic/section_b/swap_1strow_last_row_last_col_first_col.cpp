#include <iostream>
using namespace std;

int main(){
    int M,N;
    cin>>M>>N;

    int **a=new int*[M];
    for(int i=0;i<M;i++) a[i]=new int[N];

    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            cin>>a[i][j];

    // swap columns
    for(int i=0;i<M;i++){
        int temp=a[i][0];
        a[i][0]=a[i][N-1];
        a[i][N-1]=temp;
    }

    // swap rows
    for(int j=0;j<N;j++){
        int temp=a[0][j];
        a[0][j]=a[M-1][j];
        a[M-1][j]=temp;
    }

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }

    for(int i=0;i<M;i++) delete[] a[i];
    delete[] a;
}
