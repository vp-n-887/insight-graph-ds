#include<stdio.h>
#include<malloc.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}bt;

typedef struct
{
    int front;
    int rear;
    bt* val[100];
}que;


void init(que *q)
{
    q->front=0;
    q->rear=0;
}

int isempty(que q)
{
    return(q.front==q.rear);
}

int isfull(que q)
{
    return (q.rear==100);
}

void enque(que *q,bt* val)
{
    if(isfull(*q)){return;}

    q->rear=(q->rear+1);
    q->val[q->rear]=val;
}

bt* deque(que *q)
{
    if(isempty(*q)){return;}

    q->front=q->front+1;
    bt* temp=q->val[q->front];

   return temp;
}


bt* makenode(int data)
{
    bt* t=(bt*)malloc(sizeof(bt));
    t->data=data;
    t->left=NULL;
    t->right=NULL;

    return t;
}



bt* insert(bt* t,int data)
{
    bt* sub=makenode(data);

    if(!t){return sub;}

    que q;
    init(&q);
    enque(&q,t);

    while(!isempty(q))
    {
        bt* temp=deque(&q);

        if(!temp->left)
        {
            temp->left=sub;
            return t;
        }
        else{enque(&q,temp->left);}

        if(!temp->right)
        {
            temp->right=sub;
            return t;
        }
        else{enque(&q,temp->right);}
    }
    return t;
}


void inorder(bt *t)
{
    if(t){
        inorder(t->left);
        printf("%5d",t->data);
        inorder(t->right);
    }
}


int minheap(bt* t)
{
    bt* temp=t;
    if(!temp){return 1;}
    if(temp->left||temp->right){
    if(temp->left->data<temp->data||temp->right->data<temp->data){return 0;}}

    return minheap(temp->left)&&minheap(temp->right);

}

int main()
{
    bt* t=NULL;

    t=insert(t,1000);
    t=insert(t,200);
    t=insert(t,100);
    t=insert(t,150);


    if(minheap(t)==1){printf("minheap");}
    else printf("not a minheap");

    inorder(t);
    return 0;
}
