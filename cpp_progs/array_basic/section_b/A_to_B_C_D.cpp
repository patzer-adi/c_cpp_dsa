#include <iostream>
using namespace std;

int main(){
    int M,N;
    cin>>M>>N;

    int **A=new int*[M];
    int **B=new int*[M];
    int **C=new int*[M];
    int **D=new int*[M];
    int **E=new int*[M];

    for(int i=0;i<M;i++){
        A[i]=new int[N];
        B[i]=new int[N];
        C[i]=new int[N];
        D[i]=new int[N];
        E[i]=new int[N];
    }

    // Input A
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            cin>>A[i][j];

    // Copy A to B
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            B[i][j]=A[i][j];

    // C = B * B
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            C[i][j]=B[i][j]*B[i][j];

    // D = A + B + C
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            D[i][j]=A[i][j]+B[i][j]+C[i][j];

    // E = 2A + 3D
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            E[i][j]=2*A[i][j]+3*D[i][j];

    // Print E
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++)
            cout<<E[i][j]<<" ";
        cout<<endl;
    }

    for(int i=0;i<M;i++){
        delete[] A[i]; delete[] B[i]; delete[] C[i];
        delete[] D[i]; delete[] E[i];
    }
    delete[] A; delete[] B; delete[] C; delete[] D; delete[] E;
}
