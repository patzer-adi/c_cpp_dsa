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

    for(int i=0;i<M;i++){
        a[i][0]=0;
        a[i][N-1]=1;
    }

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }

    for(int i=0;i<M;i++) delete[] a[i];
    delete[] a;
}
