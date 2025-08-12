#include <stdio.h>
#include<string.h>
void run()
{
    int count = 0, flag = 0;
    char pass[5], true_pass[5] = "Ellow";
    while(count < 3)
    {
        printf("Enter password:\n");
        scanf("%s",&pass);
        if(strcmp(pass,true_pass) == 0)
        {
            printf("Account key Verified and access granted My Lord.\n");
            break;
        }
        else
        {
            printf("Thief, Wrong pass!!\n");
            count++;
        }
    }
    printf("You have exceeded Limit. You are Locked out, Thief!!!");
    
    return;
}


int main() {
    
    run();
    return 0;
}
