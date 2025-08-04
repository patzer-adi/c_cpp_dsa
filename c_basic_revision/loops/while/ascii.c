#include<stdio.h>

int main()
{
    char ch = 'A';

    while(ch <= 'Z')
    {
        printf("ASCII:%d\tChar: %c\n",ch,ch);
        ++ch;

    }
    return 0;
}
