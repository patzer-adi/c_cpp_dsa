#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n1,n2;
    char op;
    printf("+.Add\n-.Sub\n*.Mul\n/.Div\n'%'.Mod\ne.Exit\n");
    while(1)
    {
    printf("Enter operator:\n");
    scanf("%c",&op);
    printf("Enter 1st number:\n");
    scanf("%d",&n1);
    printf("Enter 2nd number:\n");
    scanf("%d",&n2);

    switch(op)
    {
        case '+':
            printf("%d + %d = %d\n",n1,n2,n1+n2);
        break;
        case '-':
            printf("%d + %d = %d\n",n1,n2,n1-n2);
        break;
        case '/':
            printf("%d + %d = %d\n",n1,n2,n1/n2);
        break;
        case '*':
            printf("%d + %d = %d\n",n1,n2,n1*n2);
        break;
        case '%':
            printf("%d + %d = %d\n",n1,n2,n1%n2);
        break;
        case 'e':
            printf("Exiting\n");
            exit (0);
            break;
        default:
            printf("Error\n");
        break;
    }
    }
    return 0;
}
