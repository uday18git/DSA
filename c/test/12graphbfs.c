#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* link;
};
int front=0,rear=0;
typedef struct node* nodeptr;
nodeptr graph[50];
int visited[50];
int queue[50];
nodeptr getnode()
{
    nodeptr q;
    q = (struct node*)malloc(sizeof(struct node));
    return q;
}
void create(int n)
{
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
}
void addq(int n)
{
    queue[rear++]=n;
}
int deleteq()
{
    return queue[front++];
}
void bfs(int v,int n)
{
    nodeptr w;
    printf("%d/t",v);
    addq(v);
    visited[v]=1;
    while(visited[n]==0)// runs till the last node is visited in the graph
    {
        v=deleteq();
        for(w=graph[v];w;w=w->link)// visits all the nodes in the v's adjacency list
        {
            if(!visited[w->data])// if it is not visited adds it to the prints it adds it to queue and marks it visited
            {
                printf("%d",w->data);
                addq(w->data);
                visited[w->data]=1;
            }
        }
    }
}
void main()
{
    int n,p,o;
    nodeptr q;
    printf("Enter the number of vertices");
    scanf("%d",&n);
    create(n);
    for(int i=0;i<n;i++)// we are creating the adjacency lists for all the vertices in the graph
    {
        graph[i]=getnode();
        printf("Enter the data for the %d vertice",i+1);
        scanf("%d",(&graph[i]->data));
        printf("Enter the number of vertice connected with this vertice");
        scanf("%d",&p);
        q=graph[i];
        for(int j=0;j<p;j++)
        {
            nodeptr temp;
            temp = getnode();
            int w;
            printf("Enter the data of %d vertices(asecending)",j+1);
            scanf("%d",&w);
            temp->data=w;
            q->link = temp;
            q=temp;
        }
        q->link=NULL;
    }
}
