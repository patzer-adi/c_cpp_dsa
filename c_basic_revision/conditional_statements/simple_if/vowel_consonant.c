#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char ch;
    printf("Enter a character:\n");
    scanf("%c",&ch);
        if( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'|| ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            printf("This character is a Vowel\n");
    else
        printf("This character is a consonant\n");
    return 0;
}