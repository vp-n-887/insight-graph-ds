#include<stdio.h>
#define MAX 10

typedef struct{
    int front;
    int rear;
    char val[MAX];
}queue;

void createque(queue *q)
{
    q->front=0;
    q->rear=0;
}

int isempty(queue q)
{
    if(q.front==q.rear){return 1;}
    return 0;
}

int isfull(queue q)
{
    if((q.rear+1)%MAX==q.front){return 1;}
    return 0;
}

void enqueue(queue *q,char val)
{
    if(isfull(*q)){return;}

    q->rear=(q->rear+1)%MAX;
    q->val[q->rear]=val;
}

void dequeue(queue *q,char *val)
{
    if(isempty(*q)){return;}

    q->front=(q->front+1)%MAX;
    *val=q->val[q->front];
}

int count(queue q)
{
    return (q.rear-q.front+MAX)%MAX;
}

int www(char a[],queue *q1,queue *q2)
{
    int period1=-1;
    int period2=-1;
    int i=0;
    char x;

    while(a[i]!='\0')
    {
        if(a[i]=='.')
        {
            if(period1==-1){period1=i;}
            else{period2=i;break;}
        }
        i++;
    }

    if(period1==-1||period2==-1){return 0;}

    for(int i=period1+1;i<period2;i++)
    {
        enqueue(q1,a[i]);
    }

    for(int i=period2+1;a[i]!='\0';i++)
    {
        enqueue(q2,a[i]);
    }

    //checking w.w
    i=0;
    while(!isempty(*q1))
    {
        dequeue(q1,&x);
        if(x!=a[i])
        {return 0;}
        i++;
    } 
    if(a[i]!='.'){return 0;}

    //checking w.w.w
    i=0;
    while(!isempty(*q2))
    {
        dequeue(q2,&x);
        if(x!=a[i])
        {return 0;}
        i++;
    } 
    if(a[i]!='.'){return 0;}
    
 if(isempty(*q1)&&isempty(*q2)){return 1;}
    else{return 0;}

}

int main()
{
    queue q1;
    queue q2;
    char a[50];
    
    createque(&q1);
    createque(&q2);
    printf("enter string: ");
    scanf("%s",a);

    if(www(a,&q1,&q2)){printf("in the foramt w.w.w");}
    else {printf("not in the format");}

    return 0;
}
