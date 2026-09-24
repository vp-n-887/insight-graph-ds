#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct{
int reg;
int cred;
double gpa;
}record;

record getdata()
{
    record r;
    scanf("%d%d%lf",&r.reg,&r.cred,&r.gpa);
    return r;
}


void display(record r[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%lf",r[i].reg,r[i].cred,r[i].gpa);
        printf("\n");
    }
}
void merge(record arr[],int start,int mid,int end)
{
    int i=start;
    int j=mid+1;
    int k=0;
    int size=end-start+1;

    record* b=(record *)malloc(size*sizeof(record));

    while(i<=mid&&j<=end)
    {
        if(arr[i].cred<arr[j].cred)
        {
            b[k]=arr[i];
            i++;
            k++;
        }

        else{
            b[k] = arr[j];
            j++;k++;
        }
    }

    while(i<=mid)
    {
        b[k]=arr[i];
        k++;
        i++;
    }

    while(j<=end)
    {
        b[k]=arr[j];
        k++;
        j++;
    }

    for(int i=0;i<size;i++)
    {
        arr[start+i]=b[i];
    }
}

void mergesort(record arr[],int start,int end)
{
    if(start<end)
    {
        int mid=(start+end)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);

        merge(arr,start,mid,end);
    }
}


int main()
{
    int n;
    scanf("%d",&n);

    record r[n];

    for(int i=0;i<n;i++)
    {
         r[i]=getdata();
    }

    mergesort(r,0,n-1);

   /* for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%lf",r[i].reg,r[i].cred,r[i].gpa);
        printf("\n");
    }*/
    display(r,n);

    return 0;



}
