#include <stdio.h>
#include <string.h>
int nfind(char str[],char pat[])
{
    int i,j,start=0;
    int lasts = strlen(str)-1;
    int lastp = strlen(pat)-1;
    int endmatch = lastp;
    for(;endmatch<=lasts;endmatch++,start++)
    {
        if(str[endmatch]==pat[lastp])
        {
            for(i=start,j=0;j<lastp && str[i]==pat[j];i++,j++);
        }
        if(j==lastp)
        {
            return start;
        }
    }
    return -1;

}
void main()
{
    // printf("this is main");
    char a[] = "ababaaabaab";
    char b[] = "baab";
    int ans = nfind(a, b);

    // printf("working");
    if(ans == -1)
    {
        printf(" not found");
    }
    else{
        printf(" \n%d",ans+1);
    }
}