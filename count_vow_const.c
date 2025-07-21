#include<stdio.h>

int main()
{
    char str[10];
    int v_cnt=0, c_cnt=0;
    printf("Enter a string:\n");
    scanf("%s",&str);
    int str_len=0;
    while(str[str_len]!= '\0')
    {
        str_len++;
    }
    for(int i = 0; i < str_len;i++)
    {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'|| str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            v_cnt ++;
        else
            c_cnt++;
    }

    printf("Vowel Count:%d\nConsonant Count:%d\n",v_cnt,c_cnt);
    return 0;
}
