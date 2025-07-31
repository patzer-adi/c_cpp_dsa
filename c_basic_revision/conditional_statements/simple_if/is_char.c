#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char ch;
    printf("Enter a character:\n");
    scanf("%c",&ch);
    if(isalpha(ch))
        printf("Is a character\n");
    else
        printf("Is Not a character\n");
    return 0;
}
