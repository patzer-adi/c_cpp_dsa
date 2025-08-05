#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n1,n2;
    int op;
    printf("1.Add\n2.Sub\n3.Div\n4.Mul\n5.Mod\n6.Exit\n");
    while(1)
    {
    printf("Enter operator:\n");
    scanf("%d",&op);
    printf("Enter 1st number:\n");
    scanf("%d",&n1);
    printf("Enter 2nd number:\n");
    scanf("%d",&n2);

    switch(op)
    {
        case 1:
            printf("%d + %d = %d\n",n1,n2,n1+n2);
        break;
        case 2:
            printf("%d + %d = %d\n",n1,n2,n1-n2);
        break;
        case 3:
            printf("%d + %d = %d\n",n1,n2,n1/n2);
        break;
        case 4:
            printf("%d + %d = %d\n",n1,n2,n1*n2);
        break;
        case 5:
            printf("%d + %d = %d\n",n1,n2,n1%n2);
        break;
        case 6:
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
