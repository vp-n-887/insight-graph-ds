#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

void insertionsort(char* arr[], int n) {

    for(int i=1;i<n;i++)
    {
        int j=i-1;
        char* key=arr[i];

        while(j>=0&&strcmp(arr[j],key)>0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    char* arr[n];

    for(int i=0;i<n;i++)
    {
        arr[i]=(char*)malloc(sizeof(char)*25);
    }

    for(int i=0;i<n;i++)
    {
        scanf("%s",arr[i]);
    }

    insertionsort(arr,n);

    for(int i=0;i<n;i++)
    {
        printf("%s\t",arr[i]);
    }

    return 0;
}




