#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node{
int data;
int count;
struct node* next;
}NODE;

NODE* makenode(int data,NODE* next)
{
    NODE* temp=(NODE*)malloc(sizeof(NODE));
    temp->data=data;
    temp->next=next;
    temp->count=1;
    return temp;
}

NODE* insert(NODE* l,int data)
{
    if(!l){return makenode(data,l);}

     if(l->data==data)
    {
        l->count=l->count+1;
        return l;
    }
    if(l->data>data)
    {
        NODE* t=makenode(data,l);
        return t;
    }

    l->next=insert(l->next,data);
    return l;
}

NODE* create()
{
    NODE* l=makenode(24,NULL);
    int n=10;
    while(n)
    {
        int x=rand()%100;
        l=insert(l,x);
        n--;
    }

    return l;
}


NODE* del(NODE* l,int data)
{
    if(!l){return l;}
    if(l->data==data)
        {
            if(l->count==1){return l->next;}
            else{l->count--;return l;}
        }
    if(l->data>data){return l;}

    l->next=del(l->next,data);
}


NODE* reset(NODE* l)
{
    return NULL;
}

NODE* clear(NODE* l,int data)
{
    if(!l){return l;}
    if(l->data==data){return l->next;}

    if(l->data>data){return l;}

    l->next=clear(l->next,data);
}

int count_node(NODE *l)
{
    NODE* temp=l;
    int count=0;
    while(temp)
    {
        count++;
        temp=temp->next;
    }
    return count;
}


int count_val(NODE* l)
{
    NODE* temp=l;
    int count=0;
    while(temp)
    {
        count=count+temp->count;
        temp=temp->next;
    }
    return count;
}

int freq(NODE* l,int data)
{
    NODE* temp=l;

    while(temp)
    {
       if(temp->data==data){return temp->count;}
       temp=temp->next;
    }
    return 0;
}


void display(NODE* l)
{
    NODE* temp=l;
     while(temp)
    {
        printf("%5d--%5d\n",temp->data,temp->count);
        temp=temp->next;
    }

    printf("\n\n");
}

int main()
{

    NODE *l;

    int c;

    do{
        printf("\n\n1.create list\n");
     printf("2.insert\n");
      printf("3.delete\n");
       printf("4.reset list\n");
        printf("5.clear value\n");
         printf("6.frequency\n");
          printf("7.total nodes\n");
           printf("8.total values\n");
            printf("9.display\n");
             printf("10.quit\n");

             printf("enter your choice: ");
             scanf("%d",&c);



             switch(c)
             {

                 case 1:{l=create();break;}

                 case 2:
                     {
                         int x;
                         printf("enter value: ");
                         scanf("%d",&x);
                         l=insert(l,x);
                         break;
                     }

                case 3:
                    {
                        int x;
                         printf("enter value: ");
                         scanf("%d",&x);
                         l=del(l,x);
                         break;
                    }

                case 4:{l=reset(l);break;}


                case 5:
                    {
                        int x;
                         printf("enter value: ");
                         scanf("%d",&x);
                         l=clear(l,x);
                         break;
                    }
                case 6:
                    {
                        int x;
                         printf("enter value: ");
                         scanf("%d",&x);
                         printf("%4d",freq(l,x));
                         break;
                    }

                case 7:
                    {
                         printf("%4d\n",count_node(l));break;
                    }

                case 8:
                    {
                         printf("%4d\n",count_val(l));break;
                    }

                case 9:
                    {
                        display(l);break;
                    }

                case 10:
                    {
                        return 0;
                    }

             }
    }while(1);



}



