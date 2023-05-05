#include <stdio.h>
#include <stdlib.h>
#define MAX 200
struct node
{
    struct node *next;
    int vertex;
};
typedef struct node* nodeptr;
void readgraph();            // create an adjecency list
void insert(int vi, int vj); // insert an edge (vi,vj)in adj.list
void DFS(int i);
int visited[MAX];
nodeptr G[20]; // heads of the linked list
int n;
void main()
{
    int i, op;
    do
    {
        printf("\n\n1)Create\n2)DFS\n4)Quit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            readgraph();
            break;
        case 2:
            for (i = 0; i < n; i++)
                visited[i] = 0;
            printf("\nStarting Node No. : ");
            scanf("%d", &i);
            DFS(i);
            break;
        }
    }while (op != 4);
}
void DFS(int i)
{
    nodeptr p;
    visited[i]=1;
    printf("%d",i);
    for(p=G[i];p;p=p->next)
    {
        if(!visited[p->vertex])
        {
            DFS(p->vertex);
        }
    }
}
void readgraph()
{
    int i, vi, vj, no_of_edges;
    printf("\nEnter no. of vertices :");
    scanf("%d", &n);
    // initialise G[] with NULL
    for (i = 0; i < n; i++)
        G[i] = NULL;
    // read edges and insert them in G[]
    printf("\nEnter no of edges :");
    scanf("%d", &no_of_edges);
    for (i = 0; i < no_of_edges; i++)
    {
        printf("\nEnter an edge (u,v) :");
        scanf("%d%d", &vi, &vj);
        insert(vi, vj);
        insert(vj, vi);
    }
}
void insert(int vi, int vj)
{
    nodeptr p, q;
    // acquire memory for the new node
    q = (nodeptr)malloc(sizeof(struct node));
    q->vertex = vj;
    q->next = NULL;
    // insert the node in the linked list for the vertex no. vi
    if (G[vi] == NULL)
        G[vi] = q;
    else
    {
        // go to the end of linked list
        p = G[vi];
        while (p->next != NULL)
            p = p->next;
        p->next = q;
    }
}
#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node* next;
    int vertex;
};
typedef struct node* nodeptr;
int visited[50];
nodeptr G[50];
void insert(int vi,int vj)
{
    nodeptr p,q;
    q = (nodeptr)malloc(sizeof(struct node));
    q -> vertex = vj;
    q->next=NULL;
    if(G[vi]==NULL)
    {
        G[vi]=q;
    }
    else
    {
        for(p=G[vi];p->next;p=p->next);
        p->next=q;
    }
}
void readgraph()
{
    int i,j,n,e,vi,vj;
    nodeptr w;
    printf("Enter the number of vertices");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        G[i]=NULL;
    }
    printf("Enter number of edges");
    scanf("%d",&e);
    printf("Enter edge (u,v): ");
    scanf("%d%d",&vi,&vj);
    insert(vi,vj);
    insert(vj,vi);
}