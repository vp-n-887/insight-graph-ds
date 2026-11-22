//1 to N
// 1 to N
//1/1-a
//-1/alog(1-a)

#include<stdio.h>
#include<malloc.h>
#include<string.h>

int hash(char *key)
{
    return key[0]-'a';
}


void insert(char* table[],char* key)
{
    int i=0;
    int hashvalue=hash(key);
    
    while(i<26)
    {
        int pos=(hashvalue+i*i)%26;
        
        if(table[pos]==NULL)
        {
            table[pos]=(char*)malloc(20*sizeof(char));
            strcpy(table[pos],key);
            return;
        }
        i++;
    }
    
    printf("table is full");
}

void search(char* table[],char* key)
{
    int i=0;
    int hashvalue=hash(key);
    
    while(i<26)
    {
        int pos=(hashvalue+i*i)%26;
        
        if(strcmp(table[pos],key)==0)
        {
            printf("found in %d",pos);
            return;
        }
        i++;
    }
    
    printf("value not found");
}

void display(char* table[])
{
    for(int i=0;i<26;i++)
    {
        printf("%s\t",table[i]);
    }
}

int main()
{
    char* arr[26];
    
    for(int i=0;i<26;i++)
    arr[i]=NULL;
    
    insert(arr,"apple");
    insert(arr,"all");
    insert(arr,"ball");
    insert(arr,"dash");
    insert(arr,"dare");
    insert(arr,"aaa");
    
    search(arr,"dare");
    
    display(arr);
    
}