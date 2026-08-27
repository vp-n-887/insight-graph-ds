#include<stdio.h>
#include<malloc.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}NODE;


NODE* makenode(int data)
{
    NODE* l=(NODE*)malloc(sizeof(NODE));
    l->data=data;
    l->left=NULL;
    l->right=NULL;

    return l;
}

int height(NODE* l)
{
    if(!l){return 0;}
    int le=height(l->left);
    int r=height(l->right);

    return 1+((le>r)?le:r);
}


int getbalance(NODE* l)
{
    if(!l){return 0;}
    return height(l->left)-height(l->right);
}

NODE* leftrotate(NODE* x)
{
    NODE* y=x->right;
    NODE* temp=y->left;

    y->left=x;
    x->right=temp;

    return y;
}

NODE* rightrotate(NODE* x)
{
    NODE* y=x->left;
    NODE* temp=y->right;

    y->right=x;
    x->left=temp;

    return y;
}

NODE* insert(NODE* l,int data)
{
    if(!l){return makenode(data);}

    if(data<l->data){l->left=insert(l->left,data);}
    if(data>l->data){l->right=insert(l->right,data);}

    int bal=getbalance(l);

    if(bal>1&&data<data<l->left->data){return rightrotate(l);}
    if(bal>1&&data>data<l->left->data){l->left=leftrotate(l->left);return rightrotate(l);}
    if(bal<-1&&data>data<l->right->data){return leftrotate(l);}
    if(bal<-1&&data<data<l->right->data){l->right=rightrotate(l->right);return leftrotate(l);}

   return l;
}


void display_level(NODE* l)
{
    if(!l){return;}

    NODE* arr[100];
    int front=0;
    int rear=0;

    arr[rear++]=l;

    while(front<rear)
    {
        int count=rear-front;

        while(count>0)
        {
            NODE* curr=arr[front++];
            printf("%5d",curr->data);

            if(curr->left){arr[rear++]=curr->left;}
            if(curr->right){arr[rear++]=curr->right;}

            count--;
        }
        printf("\n");
    }
}


int main()
{
    NODE* l=NULL;
    l=insert(l,10);
    l=insert(l,20);
    l=insert(l,30);

    display_level(l);
}



