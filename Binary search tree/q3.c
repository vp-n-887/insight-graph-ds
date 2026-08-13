#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node
{
    char data;
    struct node* left;
    struct node* right;
}bt;

bt* makenode(char data)
{
    bt* t=(bt*)malloc(sizeof(bt));
    t->data=data;
    t->left=NULL;
    t->right=NULL;

    return t;
}

bt* insert(bt *t,char data)
{
    if(!t){return makenode(data);}

    if(data<t->data){t->left=insert(t->left,data);}
    if(data>t->data){t->right=insert(t->right,data);}

    return t;
}

char min(bt *t)
{
    if(!t->right){return t->data;}
    return min(t->right);
}


bt* del(bt* t,char data)
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

int search(bt* t,char data)
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
        printf("%c",t->data);
        inorder(t->right);
    }
}

int valid(char a[100])
{
    bt* t=NULL;
    int i=0;

    while(a[i]!='\0')
    {
        if(a[i]=='D')
        {
            if(search(t,a[i+1])==1){printf("multiple declarations of same variable"); return 0;}
            else{t=insert(t,a[i+1]);}
        }

        else if(a[i]=='U')
        {
            int x=search(t,a[i+1]);
            if(x==0){printf("element used before declaration or after killing");return 0;} 
        }

        else if(a[i]=='K')
        {
            if(!t){printf("improper killing"); return 0;}
             else {t=del(t,a[i+1]);}
        }

        i=i+2;
    }
    if(!t){return 1;}
    printf("declared variable unused");return 0;
}

int main()
{
    char a[100];

    scanf("%s",a);

    if(valid(a)){printf("\tvalid");}
    else {printf("\tinvalid");}
}
