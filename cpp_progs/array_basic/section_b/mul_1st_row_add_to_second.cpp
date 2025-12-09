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

    if(M>1){
        for(int j=0;j<N;j++)
            a[1][j] += 2*a[0][j];
    }

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }

    for(int i=0;i<M;i++) delete[] a[i];
    delete[] a;
}
