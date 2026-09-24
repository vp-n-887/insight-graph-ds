#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//array
int insert_arr(int* arr,int n,int data)
{
    for(int i=0;i<n;i++){if(arr[i]==data){return 0;}}
    arr[n]=data;
    return 1;
}

int search_arr(int* arr,int n,int data)
{
    for(int i=0;i<n;i++)
    {
        if(data==arr[i]){return 0;}
    }
    return 1;
}

//sortarr
void insert_sortarr(int *arr,int n,int data)
{
    int i=n-1;
    while(i>=0&&arr[i]>data)
    {
        arr[i+1]=arr[i];
        i--;
    }
    if(i>=0&&arr[i]==data){return;}
    arr[i+1]=data;

}
int search_sortarr(int *arr,int n,int data)
{
    int start=0;
    int end=n-1;

    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==data){return 0;}
        else if(data<arr[mid]){end=mid-1;}
        else if(data>arr[mid]){start=mid+1;}
    }

    return 1;
    /*for(int i=0;i<n;i++)
    {
        if(data==arr[i]){return 0;}
    }
    return 1;*/
}

//ll
typedef struct node{
int data;
struct node* next;
}LL;

LL* makenode(int data)
{
    LL* temp=(LL*) malloc(sizeof(LL));
    temp->data=data;
    temp->next=NULL;
    return temp;
}

LL* inserthead(LL* l,int data)
{
    LL *temp=l;
    while(temp)
    {
        if(temp->data==data){return l;}
        temp=temp->next;
    }
    temp=makenode(data);
    temp->next=l;
    return temp;
}

int search_ll(LL* l,int data)
{
    if(!l){return 1;}
    if(l->data==data){return 0;}
    return search_ll(l->next,data);
}

//bst
typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}bst;

bst* makenode_bst(int data)
{
    bst* t=(bst*)malloc(sizeof(bst));
    t->data=data;
    t->left=NULL;
    t->right=NULL;

    return t;
}

bst* insert_bst(bst *t,int data)
{
    if(!t){return makenode_bst(data);}

    if(data<t->data){t->left=insert_bst(t->left,data);}
    if(data>t->data){t->right=insert_bst(t->right,data);}

    return t;
}

int search_bst(bst* t,int data)
{
    if(!t){return 1;}
    if(data==t->data){return 0;}
    if(data<t->data){return search_bst(t->left,data);}
    if(data>t->data){return search_bst(t->right,data);}
}


//avl
typedef struct NOde{
    int data;
    struct NOde* left;
    struct NOde* right;
}avl;


avl* makenode_avl(int data)
{
    avl* l=(avl*)malloc(sizeof(avl));
    l->data=data;
    l->left=NULL;
    l->right=NULL;

    return l;
}

int height(avl* l)
{
    if(!l){return 0;}
    int le=height(l->left);
    int r=height(l->right);

    return 1+((le>r)?le:r);
}


int getbalance(avl* l)
{
    if(!l){return 0;}
    return height(l->left)-height(l->right);
}

avl* leftrotate(avl* x)
{
    avl* y=x->right;
    avl* temp=y->left;

    y->left=x;
    x->right=temp;

    return y;
}

avl* rightrotate(avl* x)
{
    avl* y=x->left;
    avl* temp=y->right;

    y->right=x;
    x->left=temp;

    return y;
}

avl* insert_avl(avl* l,int data)
{
    if(!l){return makenode_avl(data);}

    if(data<l->data){l->left=insert_avl(l->left,data);}
    if(data>l->data){l->right=insert_avl(l->right,data);}

    int bal=getbalance(l);

    if(bal>1&&data<data<l->left->data){return rightrotate(l);}
    if(bal>1&&data>data<l->left->data){l->left=leftrotate(l->left);return rightrotate(l);}
    if(bal<-1&&data>data<l->right->data){return leftrotate(l);}
    if(bal<-1&&data<data<l->right->data){l->right=rightrotate(l->right);return leftrotate(l);}

   return l;
}

int search_avl(avl* l,int data)
{
    if(!l){return 1;}
    if(l->data==data){return 0;}
    if(data<l->data){return search_avl(l->left,data);}
    if(data>l->data){return search_avl(l->right,data);}
}

int main()
{
    int *a=(int*)malloc(4000*sizeof(int));
    int *s=(int*)malloc(4000*sizeof(int));
    LL* l=NULL;
    bst* t=NULL;
    avl* av=NULL;

    int n=4000;
    int count=0;

   /* while(n>0)
    {
        int x=rand()%10000;
        insert_arr(a,4000-n,x);
        insert_sortarr(s,4000-n,x);
        l=inserthead(l,x);
        t=insert_bst(t,x);
        av=insert_avl(av,x);
        n--;
    }
*/
    while(count<4000)
    {
        int x=rand()%10000;
        if(insert_arr(a,count,x))
          {
              insert_sortarr(s,count,x);
              l=inserthead(l,x);
              t=insert_bst(t,x);
              av=insert_avl(av,x);
              count++;
          }
    }


    int m=50000;
    int fail_arr=0;
    int fail_sortarr=0;
    int fail_ll=0;
    int fail_bst=0;
    int fail_avl=0;

    while(m>0)
    {
        int y=rand()%10000;
        fail_arr=fail_arr+search_arr(a,4000,y);
        fail_sortarr=fail_sortarr+search_sortarr(s,4000,y);
        fail_ll=fail_ll+search_ll(l,y);
        fail_bst=fail_bst+search_bst(t,y);
        fail_avl=fail_avl+search_avl(av,y);
        m--;
    }

    double arr=fail_arr/50000.0;
    double sortarr=fail_sortarr/50000.0;
    double ll=fail_ll/50000.0;
    double bst=fail_bst/50000.0;
    double avl=fail_avl/50000.0;




    printf("arr: %d\t%f\n",fail_arr,arr);
    printf("sort arr: %d\t%f\n",fail_sortarr,sortarr);
    printf("ll: %d\t%f\n",fail_ll,ll);
    printf("bst: %d\t%f\n",fail_bst,bst);
    printf("avl: %d\t%f\n",fail_avl,avl);


    return 0;


}


