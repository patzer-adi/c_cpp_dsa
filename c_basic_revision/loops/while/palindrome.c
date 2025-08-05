#include<stdio.h>

int main()
{
    char str[10];
    int i = 0,cnt=0,flag =1;

    printf("Enter string:\n");
    scanf("%s",&str);
    printf("String: %s\n",str);
    while(str[cnt] != '\0')
    {
        cnt++;
    }
    printf("%d\n",cnt);
    for(i=0; i < cnt && flag; i++)
    {
        if(str[i] == str[cnt - 1 -i])
            flag = 1;
        else
            flag = 0;
    }

    if(flag)
        printf("Palindrome");
    else
        printf("Not Palindrome");
    return 0;
}
