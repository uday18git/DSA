#include<stdio.h>
void main()
{   int i;
    struct ministers
    {
        char name[50];
        char announced[50][50];
        char carried_out[100][100];
    };
    struct ministers m1;
    printf("enter name of doctor ");
    scanf("%s",m1.name);
    printf("enter number of hospitals visited ");
    scanf("%s",&m1.announced);
    printf("enter schemes carried out : ");
    for(i=0;i<m1.announced;i++)
    {
        
        scanf("%s",m1.announced[i]);

    }
    printf("\n doctor name : %s",m1.name);
    printf("\n Visited hospitals : \n"); 
    for(i=0;i<m1.n;i++)
    {   
       
        puts(m1.announced[i]);
    }
}