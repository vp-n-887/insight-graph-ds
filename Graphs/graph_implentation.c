#include<stdio.h>
#include<malloc.h>
#define N 3

typedef struct{
    int arr[N][N];
}g_arr;

typedef struct node{
    int data;
    struct node* next;
}NODE;

typedef struct{
    NODE* a[N];
}graph;

typedef struct{
    int arr[10];
    int front;
    int rear;
}queue;

queue createque()
{
    queue q;
    q.front=0;
    q.rear=0;
    return q;
}

int isempty(queue q)
{
    if(q.front==q.rear){return 1;}
   
    return 0;
}

int isfull(queue q)
{
    if(q.front==0&&q.rear==9){return 1;}
    return 0;
}

void push(queue* q,int x)
{
 if(isfull(*q)){return;}
 q->rear=q->rear+1;
 q->arr[q->rear]=x;
}

void pop(queue *q,int *x)
{
    if(isempty(*q)){return;}
    q->front=q->front+1;
    *x=q->arr[q->front];
}

g_arr create()
{
    g_arr g;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            g.arr[i][j]=0;
        }
    }
    return g;
}

void addedges_arr(g_arr *g,int u,int v)
{
    g->arr[u][v]=1;
    g->arr[v][u]=1;
}


graph createlist()
{
    graph g;
    for(int i=0;i<N;i++)
    {
        g.a[i]=NULL;
    }
    return g;
}

NODE* insert(NODE* head,int v)
{
    NODE* l=(NODE*)malloc(sizeof(NODE));
    l->data=v;
    l->next=head;
    return l;
}

void addedges(graph *g,int u,int v)
{
   g->a[u]=insert(g->a[u],v);
   g->a[v]=insert(g->a[v],u);
}

//refer to the next file for seeing how to create a graph list in function...
//input<- e;
//for(int i=0;i<e;i++)
//scanf(u,v)
//addedes(g,u,v)

g_arr tomatrix(g_arr g1,graph g)
{
    for(int i=0;i<N;i++)
    {
        NODE* temp=g.a[i];
        while(temp!=NULL)
        {
            int x=temp->data;
            g1.arr[i][x]=1;
            temp=temp->next;
        }
    }
}
graph tolist(g_arr g1,graph g)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(g1.arr[i][j]!=0)
            {
                g.a[i]=insert(g.a[i],j);
            }
        }
    }
    return g;
}

void display(graph g)
{
    for(int i=0;i<N;i++)
    {
        NODE* temp=g.a[i];
        printf("%4d ->",i);
        while(temp!=NULL)
        {
            printf("%4d",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }

    printf("\n\n");
}

void BFS(graph g,int s)
{
    queue q;
    q=createque();
    int visit[N];
    for(int i=0;i<N;i++){visit[i]=0;}

    push(&q,s);
    visit[s]=1;

    while(!isempty(q))
    {
        int curr;
        pop(&q,&curr);
        printf("%4d",curr);

        NODE* temp=g.a[curr];
        while(temp!=NULL)
        {
            int neigh=temp->data;
            if(visit[neigh]==0)
            {
                push(&q,neigh);
                visit[neigh]=1;
            }
            temp=temp->next;
        }
    }
    
}


void DFS(graph g,int s,int* visited)
{
    printf("%4d",s);
    visited[s]=1;

    NODE* temp=g.a[s];

    while(temp!=NULL)
    {
        int neigh=temp->data;
        if(visited[neigh]==0)
        {
            DFS(g,neigh,visited);
        }
        temp=temp->next;
    }
}



int main()
{
    g_arr g1=create();
    addedges_arr(&g1,0,1);
    addedges_arr(&g1,0,2);

    graph g2=createlist();
    g2=tolist(g1,g2);
   

    display(g2);
   

    int visited[N];
    for(int i=0;i<N;i++)
    {visited[i]=0;}
    DFS(g2,0,visited);
        printf("\n\n");
    BFS(g2,0);
}