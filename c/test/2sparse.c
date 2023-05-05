// #include<stdio.h>
// #include<stdlib.h>
// #define MAX 100
// typedef struct 
// {
//     int row;
//     int col;
//     int val;
// }sparse;
// void readsparse(sparse a[],int m,int n)
// {
//     int i,j,k,item,p;
//     a[0].row = m;
//     a[0].col = n;
//     k=1;
//     printf("enter the elements\n");
//     for(i=0;i<m;i++)
//     {
//         for(j=0;j<n;j++)
//         {
//             scanf("%d",&item);
//             if(item==0)
//             continue;
//             a[k].row = i;
//             a[k].col = j;
//             a[k].val = item;
//             k++;
//         }
//     }
//     a[0].val = k-1;
//     printf("\n The entered sparse matrix is:\n");
//     printf("\n Row\tColumn\tValue\n");
//     for(p=0;p<=a[0].val;p++)
//     {
//         printf("%d\t",a[p].row);
//         printf("%d\t",a[p].col);
//         printf("%d\t",a[p].val);
//         printf("\n");

//     }

// }
// void fast_transpose(sparse a[],sparse b[])
// {
//     int row_terms[MAX],start_pos[MAX];
//     int i,j,p;
//     int numCols = a[0].col;
//     int numTerms = a[0].val;
//     b[0].row = numCols;
//     b[0].col = a[0].row;
//     b[0].val = numTerms;
//     if(numTerms>0)
//         {   for(i =0; i<numCols;  i++)
//                 row_terms[i] = 0;
//             for(i=1; i<=numTerms; i++)
//                 row_terms[a[i].col]++;
//                 start_pos[0]=1;
//             for(i=1; i<numCols; i++)
//                start_pos[i] = start_pos[i-1] + row_terms[i-1];
//             for(i=1; i<=numTerms; i++)
//             {  
//                 j = start_pos[a[i].col]++;
//                 b[j].row = a[i].col;
//                 b[j].col = a[i].row;
//                 b[j].val = a[i].val;
//             }
//             }
//             printf("\nThe Fast Transpose sparse matrix is:\n");
//             printf("\nRow\tColumn\tValue\n");
//             for(p=0; p<=a[0].val; p++)
//             {
//                         printf("%d\t", b[p].row);
//                         printf("%d\t", b[p].col);
//                         printf("%d\n", b[p].val);
//             }
    
// }
// void main()
// {
//         int m, n, key;
//         sparse a[MAX], b[MAX];
//         printf("\nEnter  the no of rows and columns:\t");
//         scanf("%d%d",&m, &n);
//         readsparse(a, m, n);
//         fast_transpose(a, b);
// }
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct 
{
    int row;
    int col;
    int val;
}sparce;
void readsparse(sparce a[],int m,int n)
{
    int  i,j,k,item,p;
    a[0].row=m;
    a[0].col=n;
    k=1;
    printf("Enter the elements");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&item);
            if(item==0)
            {
                continue;
            }
            a[k].row=i;
            a[k].col=j;
            a[k].val=item;
            k++;
        }
    }
    a[0].val=k-1;
    printf("\nEntered matrix is\n");
    printf("Row\tCol\tVal\n");
    for(i=0;i<=a[0].val;i++)
    {
        
        printf("%d\t%d\t%d\n",a[i].row,a[i].col,a[i].val);
    }
}
void fast_transpose(sparce a[],sparce b[])
{
    int row_terms[MAX],start_pos[MAX];
    int i,j,p;
    int numCols = a[0].col;
    int numTerms = a[0].val;
    b[0].row=numCols;
    b[0].col = a[0].row;
    b[0].val = numTerms;
    if(numTerms>0)
    {
        for(i=0;i<numCols;i++)
        {
            row_terms[i]=0;
        }
        for(i=1;i<=numTerms;i++)
        {
            row_terms[a[i].col]++; //row terms is array that consists of num of values in each column of the input a sparce matrix
        }
        start_pos[0]=1;
        for(i=1;i<numCols;i++)
        {
            start_pos[i]=start_pos[i-1]+row_terms[i-1];//***********//
        }
        for(int i=1;i<=numTerms;i++)
        {
            j=start_pos[a[i].col]++;
            b[j].col=a[i].row;
            b[j].row=a[i].col;
            b[j].val=a[i].val;
        }
    }
    printf("\nRow\tColumn\tValue\n");
            for(p=0; p<=a[0].val; p++)
            {
                        printf("%d\t", b[p].row);
                        printf("%d\t", b[p].col);
                        printf("%d\n", b[p].val);
            }
}
void main()
{
        int m, n, key;
        sparce a[MAX], b[MAX];
        printf("\nEnter  the no of rows and columns:\t");
        scanf("%d%d",&m, &n);
        readsparse(a, m, n);
        fast_transpose(a, b);
}