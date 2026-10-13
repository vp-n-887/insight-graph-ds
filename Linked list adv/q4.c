#include<stdio.h>
#include<malloc.h>

typedef struct node{
    int data;
    struct node* next;
}NODE;


typedef struct{
    NODE* top;
}stack;

NODE* makenode(int data)
{
    NODE* t=(NODE*)malloc(sizeof(NODE));
    t->data=data;
    t->next=NULL;
    return t;
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

void push(stack*s,int data)
{
    NODE* temp=makenode(data);
    temp->next=s->top;

    s->top=temp;
}

void pop(stack*s,int *data)
{
    if(isempty(*s)){*data=-1;return;}

    NODE* temp=s->top;
    *data=temp->data;

    s->top=temp->next;
    //free is the proper method but this works just fine
    //free(temp);
}


void display(stack s){
    while(!isempty(s)){
        int x;
        pop(&s, &x);
        printf("%d ", x);
    }
    printf("\n");
}

int solve(char str[]){
    stack s1 = createstack();
    int i = 0;
    int x;

    while(str[i] != '\0'){

        if(str[i] >= '0' && str[i] <= '9'){push(&s1, str[i] - '0');}

        if(str[i] == '+')
        {
            int x, y;
            pop(&s1, &x);
            pop(&s1, &y);
            push(&s1, x + y);
        }


        if(str[i] == '-')
        {
            int x, y;
            pop(&s1, &x);
            pop(&s1, &y);
            push(&s1, y - x);
        }

        if(str[i] == '*'){
            int x, y;
            pop(&s1, &x);
            pop(&s1, &y);
            push(&s1, x * y);
        }

        if(str[i] == '/'){
            int x, y;
            pop(&s1, &x);
            pop(&s1, &y);
            push(&s1, y / x);
        }


        i++;
    }

    pop(&s1, &x);
    return x;
}

int main(){
    char str[50];
    scanf("%s",str);

    printf("%d\n",solve(str));
    return 0;
}
