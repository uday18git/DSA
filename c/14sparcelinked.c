// #define MAX_SIZE 50
// typedef enum{head,entry} tagfield;
// typedef struct matrix_node *matrix_pointer;
// typedef struct entry_node
// {
//     int row;
//     int col;
//     int value;
// }entry_node;
// typedef struct matrix_node{
//     matrix_pointer down;
//     matrix_pointer right;
//     tagfield tag;
//     union{
//         matrix_pointer next;
//         entry_node entry;
//     }u;
// };
// matrix_pointer hdnode[MAX_SIZE];
// matrix_pointer mread(void)
// {
//     int num_rows,num_cols,num_terms,num_heads,i;
//     int row,col,value,current_row;
//     matrix_pointer temp,last,node;
//     printf("Enter the number of rows,columns and number of non zero terms: ");
//     scanf("%d%d%d",&num_rows,&num_cols,num_terms);
//     num_heads = (num_cols>num_rows)? num_cols:num_rows;
//     node = new_node();node->tag= entry;
//     node->u.entry.row = num_rows;
//     node->u.entry.col = num_cols;
//     if(!num_heads)node->right = node;
//     else{
//         for(i=0;i<num_heads;i++)
//         {
//             temp = new_node;
//             hdnode[i] = temp; hdnode[i] -> tag = head;
//         }
//     }
// }



// #include<stdio.h>
// void main()
// {
//     int i,j,n=5;
//     for(i=0;i<n;i++)
//     {
//         for(j=n-i ; j>1 ;j--)
//         {
//             printf(" ");
//         }
//         for(j=0;j<=i;j++)
//         {
//             printf("* ");
//         }
//         printf("\n");
//     }
// }

#include<stdio.h>
void main()
{
    int first=10;
    int second=20;
    first=first+second;
    second=first-second;
    first=first-second;
    printf("%d %d",first,second);
}