#include<iostream>

using namespace std;
void run()
{
    int n, n1, n2, n3;
    cout << "Enter 5 integers"<<endl;
    cin >> n;
    n1 = n;
    cin >> n;
    if( n < n1)
    {
        n2 = n1; n1 = n;
    }
    else n2 = n;
    cin >> n;

    if(n < n1)
    {
        n3 = n2; n2 = n1; n1 = n;
    }
    else if(n < n2)
    {
        n3 = n2; n2 = n;
    }
    else n3 = n;
    cin >> n;

    if( n < n1)
    {
        n3 = n2; n2 = n1; n1 = n;
    }
    else if( n < n2)
    {
        n3 = n2; n2 = n;
    }
    else if (n < n3)
    {
        n3 = n;
    }
    cin >> n;

    if(n < n1)
    {
        n3 = n2; n2 = n;
    }
    else if(n < n2)
    {
        n3 = n2; n2 = n;
    }
    else if( n < n3)
        n3 = n;


    cout << "Their median is: "<<n3<<endl;
}

int main()
{
    run ();
    return 0;
}
