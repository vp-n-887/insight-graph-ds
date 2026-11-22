#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct node{
    char a[20];
    struct node* next;
}list;


list* init()
{
    return NULL;
}


list* insert_list(list *l,char* key)
{
    list* temp=(list*)malloc(sizeof(list));
    strcpy(temp->a,key);
    temp->next=l;
    return temp;
}


//start
int hash(char a[])
{
    return a[0]-'a';
}

void insert(list* table[26],char a[])
{
    int hashvalue=hash(a);
    
    table[hashvalue]=insert_list(table[hashvalue],a);
}
//end


void display_list(list *l)
{
    list* temp=l;
    while(temp!=NULL)
    {
        printf("%s->",temp->a);
        temp=temp->next;
    }
}

void display(list* table[])
{
    for(int i=0;i<26;i++)
    {
        display_list(table[i]);
        printf("\n");
    }
}



int main()
{
    list* table[26];
    for(int i=0;i<26;i++)
    {
        table[i]=init();
    }
    
    insert(table,"apple");
    insert(table,"alien");
    insert(table,"all");
    insert(table,"ball");
    insert(table,"bala");
    
    display(table);
    
    
}