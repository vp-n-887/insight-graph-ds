#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct node
{
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

bt* insert(bt *t,int data)
{
    if(!t){return makenode(data);}

    if(data<t->data){t->left=insert(t->left,data);}
    if(data>t->data){t->right=insert(t->right,data);}

    return t;
}

void display(bt *t)
{
    if(t){
        display(t->left);
        printf("%5d",t->data);
        display(t->right);
    }
}

void inorder(bt* t,int *c,int k)
{
    if(!t){return;}

    inorder(t->left,c,k);
    (*c)++;

    if((*c)==k)
    {
        printf("%d\n",t->data);
        return;
    }

    inorder(t->right,c,k);
}

int preIndex = 0;

int search(int in[], int start, int end, int key)
{
    for(int i = start; i <= end; i++)
    {
        if(in[i] == key)
            return i;
    }
    return -1;
}

bst* buildTree(int in[], int pre[],
               int start, int end, int n)
{
    if(start > end || preIndex >= n)
        return NULL;

    int data = pre[preIndex++];
    bst* t = makenode(data);

    if(start == end)
        return t;

    int pos = search(in, start, end, data);

    if(pos == -1)
        return NULL;

    t->left = buildTree(in, pre, start, pos - 1, n);
    t->right = buildTree(in, pre, pos + 1, end, n);

    return t;
}

int main()
{

    int x;
    int c=0;
    bt *t=NULL;
    int k;
    scanf("%d",&k);

    for(int i=0;i<10;i++)
    {
        x=rand()%10;
        t=insert(t,x);
    }

    inorder(t,&c,k);

    display(t);
}




