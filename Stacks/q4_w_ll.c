#include<stdio.h>
#include<malloc.h>

typedef struct node{
    char data;
    struct node* next;
}NODE;

typedef struct 
{
    NODE* top;
}stack;

NODE* makenode(char data)
{
    NODE* l=(NODE* )malloc(sizeof(NODE));
    l->data=data;
    l->next=NULL;
    return l;
}

stack createstack()
{
    stack s;
    s.top=NULL;
    return s;
}

int isempty(stack s)
{
    if(s.top==NULL){return 1;}
    return 0;
}

void push(stack *s,char data)
{
    NODE* temp=makenode(data);
    temp->next=s->top;
    s->top=temp;
}

void pop(stack* s,char * data)
{
    if(isempty(*s)){*data='0';return;}

    NODE* temp=s->top;
    *data=s->top->data;
    
    s->top=temp->next;
}

void display(stack s)
{
    char x;
    while(!isempty(s))
    {
        pop(&s,&x);
        printf("%c",x);
    }
    printf("\n");
}

int balanced(stack* s, char a[10])
{
    int i=0;
    int period=-1;
    char x;

    while(a[i]!='\0')
    {
        if(a[i]=='.'){period=i;break;}
        i++;
    }

    if(period==-1){return 0;}

    for(i=0;a[i]!='\0';i++)
    {
        if(i<period){push(s,a[i]);}

        else if(i>period)
        {
            pop(s,&x);
            if(x!=a[i]){return 0;}
        }
    }

    if(isempty(*s)){return 1;}
    
}

int main()
{
    stack s=createstack();
    char a[10];

    scanf("%s",a);

   if(balanced(&s,a)){printf("well balanced");}
   else {printf("not balanced");}
}