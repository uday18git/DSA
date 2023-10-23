#include<stdio.h>
#include<string.h>
void main()
{
    int n,count=0,i,j;
    char sentence[200][200],conjunctions[100][100]={"for","and",'nor','but','or','yet','so'};
    printf("enter the number of words in the sentence");
    scanf("%d",&n);
    printf("enter the sentence ");
    for(i=0;i<n;i++)
    {
        scanf("%s",sentence[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<7;j++)
        {
            if(!(strcmp(sentence[i],conjunctions[j])))
            {
                count++;
            }

        }
    }
    printf("number of conjunctions in the sentence are %d",count);
}