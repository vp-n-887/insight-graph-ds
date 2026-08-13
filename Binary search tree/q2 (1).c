#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    int freq;
    struct node* left;
    struct node* right;
}bt;

bt* makenode(int data,int freq)
{
    bt* t=(bt*)malloc(sizeof(bt));
    t->data=data;
    t->freq=freq;
    t->left=NULL;
    t->right=NULL;

    return t;
}

bt* insert(bt *t,int data)
{
    if(!t){return makenode(data,1);}

    if(t->data==data){t->freq++;return t;}
    if(data<t->data){t->left=insert(t->left,data);}
    if(data>t->data){t->right=insert(t->right,data);}

    return t;
}

int min(bt *t)
{
    if(!t->right){return t->data;}
    return min(t->right);
}


bt* del(bt* t,int data)
{
    if(!t){return NULL;}

    if(t->data==data)
    {
        if(!t->left&&!t->right) {return NULL;}
        if(!t->left){return t->right;}
        if(!t->right){return t->left;}

        t->data=min(t->right);
        t->right=del(t->right,t->data);
        return t;
    }

        if(data<t->data){t->left=del(t->left,data);}
        else{t->right=del(t->right,data);return t;}
}

int search(bt* t,int data)
{
    if(!t){return 0;}
    if(t->data==data){return 1;}

    if(data<t->data){return search(t->left,data);}
    if(data>t->data){return search(t->right,data);}
}

void inorder(bt *t)
{
    if(t){
        inorder(t->left);
        printf("[%3d,%3d]",t->data,t->freq);
        inorder(t->right);
    }
}

int main()
{
    int x;
    bt *t=NULL;

    for(int i=0;i<500;i++)
    {
        x=rand()%10;
        if(search)
        t=insert(t,x);
    }

    inorder(t);

    printf("\n\n%d",t->freq);



}

