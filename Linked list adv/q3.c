#include<stdio.h>
#include<malloc.h>

typedef struct node{
int data;
struct node* next;
}NODE;

NODE* makenode(int data)
{
    NODE* temp=(NODE*) malloc(sizeof(NODE));
    temp->data=data;
    temp->next=NULL;
    return temp;
}

NODE* create()
{
    NODE* l=NULL;
    return l;
}

NODE* inserthead(NODE* l,int data)
{
    NODE *temp=makenode(data);
    temp->next=l;
    return temp;
}

NODE* inserttail(NODE* l,int data)
{
   if(!l){return makenode(data);}

   NODE* temp=l;
   while(temp->next)
   {
       temp=temp->next;
   }

   temp->next=makenode(data);

   return l;
}


void display(NODE* l)
{
     while(l&&l->next)
    {
        printf("%3d x",l->data);
        printf("^%d +",l->next->data);
        l=l->next->next;
    }
    printf("\n");
}


NODE* insert_term(NODE* l,int c,int e)
{
    NODE*t=l;
    NODE* prev=NULL;

    while(t&&t->next)
    {
        if(t->next->data==e){t->data=t->data+c;return l;}

         else if(e > t->next->data)
        {
            NODE *newc = makenode(c);
            NODE *newe = makenode(e);

            newc->next = newe;
            newe->next = t;

            if(prev == NULL)
            {
                return newc;
            }
            else
            {
                prev->next = newc;
                return l;
            }
        }
        
        prev = t->next;
        t = t->next->next;
    }

   // l = inserttail(l, c);
    //l = inserttail(l, e);

    return l;
}


NODE* multiply(NODE* l,int x)
{
    NODE* t=l;

    while(t)
    {
        t->data*=x;
        t=t->next->next;
    }
    return l;
}

NODE* add(NODE* l1,NODE* l2)
{
    NODE *l3 = NULL;

    while (l1)
    {
        l3 = insert_term(l3, l1->data, l1->next->data);
        l1 = l1->next->next;
    }

    while (l2)
    {
        l3 = insert_term(l3, l2->data, l2->next->data);
        l2 = l2->next->next;
    }

    return l3;
}

int main()
{
    NODE* l1=NULL;

    int n;
    printf("enter the number of terms: ");
    scanf("%d",&n);

    int c,e;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&c,&e);
        l1=inserttail(l1,c);
        l1=inserttail(l1,e);
    }

    display(l1);

    l1=insert_term(l1,4,3);

    display(l1);

    NODE *l2=multiply(l1,2);
    display(l2);

    NODE* l=NULL;
    l=insert_term(l,3,7);
    l=insert_term(l,7,2);

    NODE* l3=add(l1,l);
    display(l3);

}
