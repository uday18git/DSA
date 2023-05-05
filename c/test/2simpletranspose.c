#include<stdio.h>
typedef struct{
    int row;int col;int val;
}term;

void trans(term a[],term b[])
{
    int n,i,j,currentb;
    n=a[0].val;
    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].val=n;
    if(n>0)
    {
        currentb=1;
        for(i=0;i<a[0].col;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(a[j].col==i)
                {
                    b[currentb].row=a[j].col;
                    b[currentb].col=a[j].row;
                    b[currentb].val=a[j].val;
                    currentb++;
                }
            }
        }
    }
}

void main()
{
    int count=1,x,i;
    term a[10],b[10];
    printf("enter no of rowa cols and non zero values in matrix\n");
    scanf("%d%d%d",&a[0].row,&a[0].col,&a[0].val);
    printf("enter the elements of matrix\n");
    for(int i=0;i<a[0].row;i++)
    {
        for(int j=0;j<a[0].col;j++)
        {
            scanf("%d",&x);
            if(x!=0)
            {
                a[count].row=i;a[count].col=j;a[count].val=x;
                count++;
            }
            if(count>a[0].val)
            break;
        }
        if(count>a[0].val)
        break;
    }
    trans(a,b);
    printf("transpose is\n");
    for(i=1;i<=b[0].val;i++)
    {
        printf("\n%d,%d,%d\n",b[i].row,b[i].col,b[i].val);
    }

}
