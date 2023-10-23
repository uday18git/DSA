#include <stdio.h>
void main()
{
    int i, n;
    struct minister
    {
        char name[50];
        char adress[50];
        char achievments[50];
    };
    printf("enter number of ministers : ");
    scanf("%d", &n);
    struct minister m1[50];
    for (i = 0; i < n; i++)
    {
        printf("\nenter name ");
        scanf("%s", m1[i].name);
        printf("enter adress ");
        scanf("%s", m1[i].adress);
        printf("enter achievements ");
        scanf("%s", m1[i].achievments);
        
    }
    for ( i = 0; i < n; i++)
    {   printf("\n %d th minister details",i+1);
        printf("\n name : %s", m1[i].name);
        printf("\n adress : %s", m1[i].adress);
        printf("\n achievements : %s", m1[i].achievments);
    }
    
}