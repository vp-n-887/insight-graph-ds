#include<stdio.h>
#include<malloc.h>
#define MAX 20


typedef struct{
  int adj[8][8];
}graph_arr;

typedef struct node{
int vertex;
struct node *next;
}NODE;

typedef struct
{
    NODE* adj[MAX];
}graph;


NODE* insert(NODE* head,int vertex)
{
    NODE* l=(NODE*)malloc(sizeof(NODE));
    l->vertex=vertex;
    l->next=head;
    return l;
}
/*
void creategraph(graph g,int n,int e)
{
    for(int i=0;i<n;i++)
    {
        g.adj[i]=NULL;
    }
 printf("enter vertices of edges,\n");
    for(int i=0;i<e;i++)
    {
    int u,v;
    scanf("%d%d",&u,&v);

    g.adj[u]=insert(adj[u],v);
    g.adj[v]=insert(adj[v],u);
    }
}
*/

graph tolist(graph_arr a,int n)
{
    graph g;

    for(int i=0;i<n;i++){g.adj[i]=NULL;}

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a.adj[i][j]==1)
            {
                g.adj[i]=insert(g.adj[i],j);
            }
        }
    }

    return g;
}

void display(graph g,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d->",i);
        NODE* temp=g.adj[i];
        while(temp!=NULL)
        {
            printf("%5d",temp->vertex);
            temp=temp->next;
        }
        printf("\n");
    }
}

void DFS(graph g,int vertex,int *visited,int k)
{
    if(k<0){return;}
    printf("%5d",vertex);
    visited[vertex]=1;
    NODE* temp=g.adj[vertex];

    while(temp!=NULL)
    {
        int neighbour=temp->vertex;
        if(visited[neighbour]==0)
        {
            DFS(g,neighbour,visited,k-1);
        }
        temp=temp->next;
    }
}

int main()
{
    int n,e;

   graph_arr g = {
    .adj = {
        {0,1,0,0,0,1,0,0},
        {1,0,1,1,0,0,0,0},
        {0,1,0,0,0,0,0,0},
        {0,1,0,0,1,0,0,0},
        {0,0,0,1,0,0,1,0},
        {1,0,0,0,0,0,1,1},
        {0,0,0,0,1,1,0,0},
        {0,0,0,0,0,1,0,0}
    }
};

    /*int visit[8];
    for(int i=0;i<8;i++)
    {
        visit[i]=0;
    }

    printf("Bfs :\n");
    BFS_matrix(g,8,0);
    printf("\nDfs :\n");
    DFS_matrix(g,visit,0,8);
    printf("\n");
*/
    printf("display\n");
    graph g1=tolist(g,8);
    display(g1,8);

    int visit[8];
    for(int i=0;i<8;i++)
    {
        visit[i]=0;
    }

    int k=1;

   // printf("Bfs :\n");
   // BFS(g1,8,0);
    printf("\nadjacency vertices :\n");
    DFS(g1,0,visit,&k);
     printf("\n");

}
