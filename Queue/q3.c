#include<stdio.h>
#define MAX 10

typedef struct{
    int front;
    int rear;
    char val[MAX];
}queue;

typedef struct{
char val[MAX];
int top;
}stack;

void createque(queue *q)
{
    q->front=0;
    q->rear=0;
}

int qisempty(queue q)
{
    if(q.front==q.rear){return 1;}
    return 0;
}

int qisfull(queue q)
{
    if((q.rear+1)%MAX==q.front){return 1;}
    return 0;
}

void enqueue(queue *q,char val)
{
    if(qisfull(*q)){return;}

    q->rear=(q->rear+1)%MAX;
    q->val[q->rear]=val;
}

void dequeue(queue *q,char *val)
{
    if(qisempty(*q)){return;}

    q->front=(q->front+1)%MAX;
    *val=q->val[q->front];
}

int count(queue q)
{
    return (q.rear-q.front+MAX)%MAX;
}


stack createstack()
{
    stack s;
    s.top=0;
    return s;
}

int sisempty(stack s)
{
   if(s.top==0){return 1;}
   return 0;
}

int sisfull(stack s)
{
    if(s.top==MAX-1){return 1;}
    return 0;
}
void push(stack *s,char val)
{
    if(sisfull(*s)){return;}

    s->top=s->top+1;
    s->val[s->top]=val;
}

void pop(stack *s,char *val)
{
    if(sisempty(*s)){return;}

    *val=s->val[s->top];
    s->top=s->top-1;

}

int wwwr(char a[],queue *q,stack *s)
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
        enqueue(q,a[i]);
    }

    for(int i=period2+1;a[i]!='\0';i++)
    {
        push(s,a[i]);
    }

    i=0;
    while(!qisempty(*q))
    {
        dequeue(q,&x);
        if(x!=a[i]){return 0;}
        i++;
    }
    if(a[i]!='.'){return 0;}

    i=0;
    while(!sisempty(*s))
    {
        pop(s,&x);
        if(x!=a[i]){return 0;}
        i++;
    }

     if(qisempty(*q)&&sisempty(*s)){return 1;}
    else {return 0;}
}


int main()
{
    queue q;
    stack s;
    char a[50];

    s=createstack();
    createque(&q);
    printf("enter string: ");
    scanf("%s",a);

    if(wwwr(a,&q,&s)){printf("in the format w.w.w(r)");}
    else{printf("not in the format");}

    return 0;


}
