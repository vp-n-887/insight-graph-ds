#include<stdio.h>
#include<malloc.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}bt;

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
    if(!t){return makenode(data);}

    if(data<t->data){t->left=insert(t->left,data);}
    if(data>t->data){t->right=insert(t->right,data);}

    return t;
}

int height(bt* t)
{
    if(!t){return 0;}

    int l=height(t->left);
    int r=height(t->right);

    return (l>r)?l+1:r+1;
}

int max(bt* t)
{
    if(!t->right){return t->data;}
    return max(t->right);
}

bt* delete(bt* t,int data)
{
    if(!t){return t;}

    if(data<t->data){t->left=delete(t->left,data);}
    if(data>t->data){t->right=delete(t->right,data);}

    if(t->data==data)
    {
        if(!t->left&&!t->right){return NULL;}
        if(!t->left){return t->right;}
        if(!t->right){return t->left;}
      
            t->data=max(t->right);
            t->right=delete(t->right,t->data);
        
       
    }
    return t;
}

int smallest(bt* t,int *k)
{
    if(!t){return -1;}

    smallest(t->left,k);
    (*k)--;
    if(*k==0){return t->data;}

    smallest(t->right,k);
}

int largest(bt* t,int *k)
{
    if(!t){return -1;}

    largest(t->right,k);
    (*k)--;

    if(*k==0){return t->data;}
    largest(t->left,k);
}

int compare(bt* t1,bt* t2)
{
    if(!t1&&!t2){return 1;}
    if(!t1||!t2){return 0;}

    return compare(t1->left,t2->left)&&compare(t1->right,t2->right);
}

bt* copy(bt *t)
{
    if(!t){return t;}

    bt* temp=makenode(t->data);
    temp->left=copy(t->left);
    temp->right=copy(t->right);

    return temp;
}