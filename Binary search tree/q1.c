#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct node
{
    char data[500];
    struct node* left;
    struct node* right;
}bt;

bt* makenode(char data[500])
{
    bt* t=(bt*)malloc(sizeof(bt));
    strcpy(t->data,data);
    t->left=NULL;
    t->right=NULL;

    return t;
}

bt* insert(bt *t,char data[500])
{
    if(!t){return makenode(data);}

    if(strcmp(data,t->data)<0){t->left=insert(t->left,data);}
    if(strcmp(data,t->data)>0){t->right=insert(t->right,data);}

    return t;
}

char* max(bt *t)
{
    if(!t->right){return t->data;}
    return max(t->right);
}

bt* del(bt* t,char data[500])
{
    if(!t){return NULL;}

    if(strcmp(data,t->data)==0)
    {
        if(!t->left&&!t->right) {return NULL;}
        if(!t->left){return t->right;}
        if(!t->right){return t->left;}

        strcpy(t->data,max(t->right));
      // t->data=min(t->right);
        t->right=del(t->right,t->data);
        return t;
    }

        if(strcmp(data,t->data)<0){t->left=del(t->left,data);}
        else{t->right=del(t->right,data);return t;}
}


void inorder(bt *t)
{
    if(t){
        inorder(t->left);
        printf("%s\t",t->data);
        inorder(t->right);
    }
}

int count_leaves(bt *t)
{
    if(!t)
        return 0;

    if(!t->left && !t->right)
        return 1;

    return count_leaves(t->left) + count_leaves(t->right);
}

int one_child(bt *t)
{
    if(!t)
        return 0;

    if((t->left&&!t->right)||(!t->left&&t->right))
        return 1 + one_child(t->left) + one_child(t->right);

    return one_child(t->left) + one_child(t->right);
}

int two_child(bt *t)
{
    if(!t){return 0;}

    if(t->left&&t->right){return 1 + two_child(t->left)+two_child(t->right);}

    return two_child(t->left)+two_child(t->right);
}

int main()
{
    int n;
    char a[500];
    bt* t=NULL;

    scanf("%d",&n);

    while(n)
    {
        scanf("%s",a);
        t=insert(t,a);
        n--;
    }

    printf("\nno child: %d\n",count_leaves(t));
    printf("\n\n");
    printf("\n1 child: %d\n",one_child(t));
    printf("\n\n");
    printf("\n2 child: %d\n",two_child(t));
    printf("\n\n");
    inorder(t);
}

