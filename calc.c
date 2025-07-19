#include<stdio.h>

int main()
{
    int n1,n2;
    char ch;
    printf("Enter operator:\n");
    scanf("%c",&ch);
    printf("Enter 1st number:\n");
    scanf("%d",&n1);
    printf("Enter 2nd number:\n");
    scanf("%d",&n2);
    switch(ch)
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
        default:
            printf("Error\n");
        break;
    }
    return 0;
}
