#include<stdio.h>

int main()
{
    int s1,s2,s3,s4,s5,total;
    float per;
    char grade;
    printf("Enter marks of English\n");
    scanf("%d",&s1);
    printf("Enter marks of Marathi\n");
    scanf("%d",&s2);
    printf("Enter marks of Sanskrit\n");
    scanf("%d",&s3);
    printf("Enter marks of History\n");
    scanf("%d",&s4);
    printf("Enter marks of Geography\n");
    scanf("%d",&s5);
    total = s1 + s2 + s3 + s4 + s5;
    printf("total:%d\n",total);

    if(total > 500) { printf("Wrong marks as input\n"); return ;}
    else
    {
    per = (total / 5);

    printf("Percentage : %f\n",per);

    if(per >= 90)
        grade = 'A';
    else if(per >= 80 && per < 90)
        grade = 'B';
    else if(per >= 70 && per < 80)
        grade = 'C';
    else if(per >= 60 && per < 70)
        grade = 'D';
    else if(per >= 50 && per <= 40)
        grade = 'E';
    else if(per < 40)
        grade = 'F';

    printf("Grade is : %c",grade);
    }
    return 0;
}