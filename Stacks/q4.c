#include<stdio.h>
#define MAX_SIZE 10


typedef struct{
char val[MAX_SIZE];
int top;
}stack;

stack createstack()
{
    stack s;
    s.top=0;
    return s;
}

int isempty(stack s)
{
   if(s.top==0){return 1;}
   return 0;
}

int isfull(stack s)
{
    if(s.top==MAX_SIZE-1){return 1;}
    return 0;
}
void push(stack *s,char val)
{
    if(isfull(*s)){return;}

    s->top=s->top+1;
    s->val[s->top]=val;
}

void pop(stack *s,char *val)
{
    if(isempty(*s)){return;}

    *val=s->val[s->top];
    s->top=s->top-1;

}

void print(stack s)
{
     while(!isempty(s))
    {
        char b;
        pop(&s,&b);
        printf("%c",b);
    }
}

int wwr(stack *s,char a[])
{
   int i=0;
   char x;
   while(a[i]!='\0')
   {
       if(a[i]=='.'){break;}
       else{push(s,a[i]);}
       i++;
   }
   i++;
   while(a[i]!='\0')
   {
       if(isempty(*s)){return 0;}
      char x;
       pop(s,&x);
       if(a[i]!=x){return 0;}
       i++;
   }
   if(isempty(*s)){return 1;}
   return 0;
}

int main()
{
    stack s1;

    s1=createstack();
    char a[10];
    //char x;
    //int format=1;

    printf("enter string: ");
    scanf("%s",a);

    /*int i=0;
    while(a[i]!='0')
    {
        if(a[i]=='.'){i++;break;}
        push(&s1,a[i]);
        i++;
    }

    while(!isempty(s1))
    {
        pop(&s1,&x);
        if(x!=a[i]){format=0;break;}
        i++;
    }*/

    if(wwr(&s1,a)){printf("in format w.w(reverse)");}
    else{printf("not in the format");}
    return 0;
}
