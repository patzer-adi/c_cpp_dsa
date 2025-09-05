#include<stdio.h>

void fibo_series(int n)
{
    int a = 0, b = 1, c;

    if (n >= 0)
        printf("%d ", a);
    if (n >= 1)
        printf("%d ", b);

    for (int i = 2; i <= n; ++i)
    {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }

    printf("\n");
}



int fibo_rec(int n)
{
    if(n <= 1)
            return n;

    else
        return fibo_rec(n-1) + fibo_rec(n-2);
}

int fibo_iter(int n)
{

    if (n < 2)
        return n;

    int fib[n + 1]={};
    fib[0] = 0;
    fib[1] = 1;
    int i;

    for(i = 2; i <= n; ++i)
    {
        fib[i] = fib[i-1] + fib[i -2];
    }
    return fib[n];
}


void run()
{
    int n,opt,fibo_val;

    printf("Enter a number:\n");
    scanf("%d",&n);


    printf("Enter a 0 for Recursive Algo\n1 for Iterative Algo\n2 for printig series:\n");
    scanf("%d",&opt);


    if(opt == 0)
        fibo_val = fibo_rec(n);
    else if(opt == 1)
       fibo_val = fibo_iter(n);
    else
    {
        fibo_series(n);
        return;
    }

    printf("Fibonaaci Value of %d is %d\n",n,fibo_val);
    return;
}


int main()
{
    run();
    return 0;
}
