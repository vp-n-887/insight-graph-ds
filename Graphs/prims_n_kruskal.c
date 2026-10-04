#include<stdio.h>
#include<malloc.h>
#define N 6

typedef struct{
    int arr[N][N];
}g_arr;

typedef struct node{
    int data;
    int weight;
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

void addedges_arr(g_arr *g,int u,int v,int w)
{
    g->arr[u][v]=w;
    g->arr[v][u]=w;
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

NODE* insert(NODE* head,int v,int w)
{
    NODE* l=(NODE*)malloc(sizeof(NODE));
    l->data=v;
    l->weight=w;
    l->next=head;
    return l;
}

void addedges(graph *g,int u,int v,int w)
{
   g->a[u]=insert(g->a[u],v,w);
   g->a[v]=insert(g->a[v],u,w);
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
            int w=temp->weight;
            g1.arr[i][x]=w;
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
                g.a[i]=insert(g.a[i],j,g1.arr[i][j]);
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
        printf("%4d ->    ",i);
        while(temp!=NULL)
        {
            printf("%4d(%d)->",temp->data,temp->weight);
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


graph prims(graph g,int start)
{
    graph mst=createlist();
    int visit[N]={0};
    int sum=0;
    int edge_count=0;

    visit[start]=1;

    while(edge_count<N-1)
    {
    int u=-1;
    int v=-1;
    int min=9999;

    for(int i=0;i<N;i++)
    {
        if(visit[i]==1)
        {
            NODE* temp=g.a[i];

            while(temp!=NULL)
            {
                int neigh=temp->data;
                int weight=temp->weight;

                if(visit[neigh]==0&&weight<min)
                {
                    min=weight;
                    u=i;
                    v=neigh;
                }

                temp=temp->next;
            }
        }
    }

    if(u!=-1&&v!=-1)
    {
        addedges(&mst,u,v,min);
        visit[v]=1;
        sum=sum+min;
        edge_count++;
    }

    else{
        printf("graph is disconnected");
    }

}
    printf("\n\nsum = %4d",sum);
    return mst;
}

//kruskal--------------
//min heap structure to store edges

typedef struct{
    int u;
    int v;
    int weight;
}EDGE;

typedef struct{
    EDGE arr[50];
    int size;
}minheap;

minheap createheap()
{
    minheap h;
    h.size=0;
    return h;
}

void insertedges(minheap *h,EDGE e)
{
  int i=h->size;

  h->arr[i]=e;
  h->size++;

  while(i>0)
  {
    int parent=(i-1)/2;

    if(h->arr[parent].weight<=h->arr[i].weight){break;}

    EDGE temp=h->arr[parent];
    h->arr[parent]=h->arr[i];
    h->arr[i]=temp;


    i=parent;
  }

}

EDGE deletemin(minheap *h)
{
    EDGE min=h->arr[0];
    
    h->size--;
    h->arr[0]=h->arr[h->size];

    int i=0;

    while(1)
    {
        int left=2*i+1;
        int right=2*i+2;

        int smallest=i;
        
        if(left<h->size&&h->arr[left].weight<h->arr[smallest].weight){smallest=left;}
        if(right<h->size&&h->arr[right].weight<h->arr[smallest].weight){smallest=right;}

        if(smallest==i){break;}

        EDGE temp=h->arr[i];
        h->arr[i]=h->arr[smallest];
        h->arr[smallest]=temp;

        i=smallest;
    }

    return min;
}


int findparent(int parent[],int x)
{
    while(parent[x]!=x)
    {
        x=parent[x];
    }

    return x;
}

void unionset(int parent[],int u,int v)
{
    int pu=findparent(parent,u);
    int pv=findparent(parent,v);

    parent[pu]=pv;
}

graph kruskals(graph g)
{
    minheap h=createheap();
    graph mst=createlist();
    int edge_count=0;
    int sum=0;
    int parent[N];

    for(int i=0;i<N;i++){parent[i]=i;}

    for(int i=0;i<N;i++)
    {
        NODE* temp=g.a[i];
        while(temp!=NULL)
        {
            int v=temp->data;
            int w=temp->weight;

            EDGE e;
            e.u=i;
            e.v=v;
            e.weight=w;

            insertedges(&h,e);

            temp=temp->next;
        }
    }

    while(edge_count<N-1&&h.size>0)
    {
        EDGE e=deletemin(&h);
        int u=e.u; int v=e.v;  int weight=e.weight;

        int pu=findparent(parent,u);
        int pv=findparent(parent,v);

        if(pu!=pv)
        {
            addedges(&mst,u,v,weight);
            unionset(parent,u,v);
            edge_count++;
            sum=sum+weight;
        }

        //if(pu==pv){it forms a cycle so avoid it}
    }

    if(edge_count!=N-1){printf("graph is disconnected");}

    printf("\n\nsum = %4d\n",sum);
    return mst;

}



int main()
{
  
    graph g2=createlist();
    addedges(&g2,0,1,16);
    addedges(&g2,0,5,21);
    addedges(&g2,0,4,19);
    addedges(&g2,1,2,5);
    addedges(&g2,1,3,6);
    addedges(&g2,1,5,11);
    addedges(&g2,2,3,10);
    addedges(&g2,3,5,14);
    addedges(&g2,3,4,18);
    addedges(&g2,4,5,33);

   

    display(g2);
   

 
    graph mst_p=prims(g2,2);
    display(mst_p);
    printf("\n\n");

    
    graph mst_k=kruskals(g2);
    display(mst_k);
    
}