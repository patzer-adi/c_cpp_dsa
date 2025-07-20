#include<stdio.h>

int main()
{
    char str[10], str_rev[10];
    int i = 0,cnt=0;

    printf("Enter string:\n");
    scanf("%s",&str);
    printf("String: %s\n",str);

    while(str[cnt] != '\0')
    {
        cnt++;
    }
    printf("%d\n",cnt);
    for(i=0; i < cnt; i++)
    {
        str_rev[i] = str[cnt - 1 -i];
    }
    printf("String: %s\nRevserse String: %s\n",str,str_rev);

    return 0;
}
