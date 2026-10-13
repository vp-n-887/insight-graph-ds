#include<stdio.h>
#include<malloc.h>

typedef struct node{
int data;
struct node* next;
}NODE;

NODE* makenode(int data,NODE* next)
{
    NODE* temp=(NODE*) malloc(sizeof(NODE));
    temp->data=data;
    temp->next=next;
    return temp;
}

NODE* insert_sort(NODE*l,int data)
{
    if(!l){return makenode(data,NULL);}

    if(l->data>data)
    {
        return makenode(data,l);
    }

    l->next=insert_sort(l->next,data);
    return l;
}

NODE* del_sort(NODE*l,int data)
{
    if(!l){return l;}

    if(l->data>data){return l;}

    if(l->data==data){return l->next;}

    l->next=del_sort(l->next,data);
    return l;
}

void print_ascnd(NODE* l)
{

    while(l)
    {
        printf("%5d",l->data);
        l=l->next;
    }
    printf("\n");
}

void print_rv(NODE* l)
{
    if(l)
    {
        print_rv(l->next);
        printf("%5d",l->data);
    }
}



int main()
{
    NODE* l=NULL;

    l=insert_sort(l,7);
    l=insert_sort(l,1);
    l=insert_sort(l,4);
    l=insert_sort(l,8);
    l=insert_sort(l,6);

    print_ascnd(l);
    print_rv(l);
    printf("\ndeleting 4....\n");

    l=del_sort(l,4);
    print_ascnd(l);
    print_rv(l);
}
