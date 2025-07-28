#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char ch;
    printf("Enter a character:\n");
    scanf("%c",&ch);
    if(isalpha(ch))
        printf("This is a character\n");
    else if(isalnum(ch))
        printf("This character is alpha numeric\n");
    else if(isdigit(ch))
        printf("This character is a digit number\n");
    else
        printf("This is a speical character\n");
    return 0;
}
