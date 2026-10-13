#include<stdio.h>
#include<malloc.h>

typedef struct node{
int data;
struct node* next;
}NODE;

NODE* makenode(int data,NODE* next)
{
    NODE* l=(NODE*)malloc(sizeof(NODE));
    l->data=data;
    l->next=next;
    return l;
}

NODE* insert_circ_tail(NODE*l,int data)
{
    if(!l){NODE* t=makenode(data,NULL);t->next=t; return t;}

    NODE* t=makenode(data,l->next);
    l->next=t;

    l=t;
    return l;
}

void search_pred_succ(NODE* l,int data)
{
    NODE* t=l;
    int found=0;

   do
    {
        if(t->next->data==data)
        {
            found=1;
            printf("predecessor: %d\n",t->data);
            printf("successor: %d\n",(t->next)->next->data);
            return;
        }
        t=t->next;
    }while(t!=l);
    if(found==0){printf("not available");}
}

int count(NODE*l)
{
    NODE* t=l;
    int count=0;

    do{
        count++;
        l=l->next;
    }while(t!=l);

    return count;
}

NODE* reverse(NODE*l)
{
    if(l==NULL||l->next==l){return l;}

    NODE* head=l->next;
    NODE* prev=l;
    NODE* curr=head;
    NODE* next;

    do{
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }while(curr!=l);

   l->next=prev;
    return head;
}


void display(NODE* l)
{
   NODE*t=l->next;

   do{
    printf("%5d",t->data);
    t=t->next;
   }
   while(t!=l->next);
   printf("\n\n");
}



int main()
{
    NODE* l1=NULL;

    l1=insert_circ_tail(l1,5);
    l1=insert_circ_tail(l1,10);
    l1=insert_circ_tail(l1,20);
    l1=insert_circ_tail(l1,30);


    display(l1);
    int x=count(l1);
    printf("%d\n",x);

    search_pred_succ(l1,30);

    NODE* l2=reverse(l1);
    display(l2);



    return 0;

}
