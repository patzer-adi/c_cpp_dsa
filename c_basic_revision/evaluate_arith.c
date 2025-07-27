#include<stdio.h>

int main()
{
    float n1,n2,ansf;
    int ansi;
    printf("Enter a number:\n");
    scanf("%f %f",&n1,&n2);
    ansi = n1/n2;
    printf("Answer: n1/n2: %d\n",ansi);
    ansi = n2/n1;
    printf("Answer: n2/n1: %d\n",ansi);

    printf("Float:\n");
    ansf = n1/n2;
    printf("Answer: n1/n2: %f\n",ansf);
    ansf = n2/n1;
    printf("Answer: n2/n1: %f\n",ansf);

    return 0;
}
