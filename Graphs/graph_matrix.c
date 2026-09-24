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

void addedges(graph g,int u ,int v)
{
    g.adj[u]=insert(g.adj[u],v);
    g.adj[v]=insert(g.adj[v],u);
}

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

    addedges(g,u,v);
   /* g.adj[u]=insert(adj[u],v);
    g.adj[v]=insert(adj[v],u);*/
    }
}


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
              //cant use add edges here
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


/*graph create(int n)
{
    graph g;
    g.adj[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",g.adj[i][j]);
        }
    }

    return g;
}*/

typedef struct
{
    int front;
    int rear;
    int val[MAX];
}que;

que init()
{
    que q;
    q.front=0;
    q.rear=0;
    return q;
}

int isempty(que q)
{
    return(q.front==q.rear);
}

int isfull(que q)
{
    return((q.rear+1)%MAX==q.front);
}

void push(que *q,int x)
{
    if(isfull(*q))
        return;

    q->rear=(q->rear+1)%MAX;
    q->val[q->rear]=x;
}

void pop(que *q,int *x)
{
    if(isempty(*q))
        return;

    q->front=(q->front+1)%MAX;
    *x=q->val[q->front];
}

void BFS_matrix(graph_arr g,int n,int start)
{
    int visit[n];
    que q=init();
    for(int i=0;i<n;i++){visit[i]=0;}

    visit[start]=1;
    push(&q,start);

    while(!isempty(q))
    {
        int curr;
        pop(&q,&curr);
        printf("%5d",curr);

        for(int i=0;i<n;i++)
        {
            if(g.adj[curr][i]==1&&visit[i]==0)
            {
                visit[i]=1;
                push(&q,i);
            }
        }
    }

}


void DFS_matrix(graph_arr g,int* visit,int start,int n)
{
    visit[start]=1;
    printf("%5d",start);

    for(int i=0;i<n;i++)
    {
        if(visit[i]==0&&g.adj[start][i]==1)
        {
            DFS_matrix(g,visit,i,n);
        }
    }
}

void BFS(graph g,int n,int start)
{
    int visit[n];
    que q=init();

    for(int i=0;i<n;i++)
    {
        visit[i]=0;
    }

    visit[start]=1;
    push(&q,start);

    while(!isempty(q))
    {
        int curr;
        pop(&q,&curr);
        printf("%5d",curr);

        NODE* temp=g.adj[curr];
        while(temp!=NULL)
        {
            int neighbour=temp->vertex;
            if(visit[neighbour]==0)
            {
                visit[neighbour]=1;
                push(&q,neighbour);
            }
             temp=temp->next;
        }
    }
}

void DFS(graph g,int v,int* visited)
{
    printf("%5d",v);
    visited[v]=1;
    NODE* temp=g.adj[v];

    while(temp!=NULL)
    {
        int neighbour=temp->vertex;
        if(visited[neighbour]==0)
        {
            DFS(g,neighbour,visited);
        }
        temp=temp->next;
    }
}




int main()
{
    int n,e;
   // printf("veritces: ");
   // scanf("%d",&n);

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
  // graph g;
    //g.adj[8][8]=adj;

    int visit[8];
    for(int i=0;i<8;i++)
    {
        visit[i]=0;
    }

    printf("Bfs :\n");
    BFS_matrix(g,8,0);
    printf("\nDfs :\n");
    DFS_matrix(g,visit,0,8);
    printf("\n");

    printf("display\n");
    graph g1=tolist(g,8);
    display(g1,8);

    for(int i=0;i<8;i++)
    {
        visit[i]=0;
    }

     printf("Bfs :\n");
    BFS(g1,8,0);
    printf("\nDfs :\n");
    DFS(g1,0,visit);
     printf("\n");

}
