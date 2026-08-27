#include<stdio.h>
#include<malloc.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}NODE;

NODE* makenode(int data)
{
    NODE* l=(NODE*)malloc(sizeof(node));
    l->data=data;
    l->height=1;
    l->left=NULL;
    l->right=NULL;

    return l;
}

int height(NODE* l)
{
    if(!l){return 0;}
    return l->height;
}


int getbalance(NODE* l)
{
    if(!l){return 0;}
    return height(l->left)-(l->right);
}

NODE* leftrotate(NODE* x)
{
    NODE* y=x->right;
    NODE* temp=y->left;

    y->left=x;
    x->right=temp;

    x->height=1+max(height(x->left))
}

