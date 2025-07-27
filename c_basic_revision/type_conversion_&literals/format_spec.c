#include<stdio.h>

int main()

{
    int n;
    float a;
    char ch;
    printf("Enter a character:");
    scanf("%c",&ch);
    printf("Enter an integer number:");
    scanf("%d",&n);
    printf("Enter a float number:");
    scanf("%f",&a);


    printf("\nInt :%d\nFloat:%d\nCharacter:%c\n",n,a,ch);
    return 0;
}
