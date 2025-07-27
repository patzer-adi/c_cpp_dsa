#include<stdio.h>

int main()
{
    int n1,n2;
    printf("Enter two numbers:\n");
    scanf("%d %d",&n1,&n2);
    printf("Answer: n1/n2: %d\n",n1/n2);
    printf("Answer: n2/n1: %d\n",n2/n1);
    printf("same ans with diff format specifier\n");
    printf("Answer 1.1: n2/n1: %f\n",n2/n1);
    printf("Answer 1.2: n1/n2: %f\n",(float)(n1)/n2);
    printf("Answer 1.3: n2/n1: %f\n",(float)n2/(n1));
    printf("Answer 1.4: n1/n2: %f\n",(float)(n1)/(float)(n2));
    printf("Answer 1.4: n2/n1: %f\n",(float)(n2)/(float)(n1));


}
