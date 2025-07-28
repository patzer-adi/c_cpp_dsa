#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char ch;
    printf("Enter a character:\n");
    scanf("%c",&ch);
    if(isupper(ch))
        printf("This character is upper case\n");
    else
        printf("This character is lower case\n");
    return 0;
}
