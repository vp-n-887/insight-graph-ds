#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct{
int d;
int m;
int y;
}dob;

typedef struct{
int reg;
dob DOB;
}record;


int dob_cmp(dob d1,dob d2)
{
    //d2 should be greater
    if (d1.y<d2.y)
        return 1;

    if (d1.y>d2.y)
        return 0;

    if (d1.m<d2.m)
        return 1;

    if (d1.m>d2.m)
        return 0;

    if (d1.d<d2.d)
        return 1;

    return 0;
}


record getdata()
{
    record r;
    scanf("%d%d%d%d",&r.reg,&r.DOB.d,&r.DOB.m,&r.DOB.y);
    return r;
}

void display(record r[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d-%d-%d",r[i].reg,r[i].DOB.d,r[i].DOB.m,r[i].DOB.y);
        printf("\n");
    }
}

void swap(record *a,record *b)
{
    record temp=*a;
    *a=*b;
    *b=temp;
}


int partition(record arr[],int start,int end)
{
    dob pivotal=arr[start].DOB;
    int i=start;

    for(int j=start+1;j<=end;j++)
    {
        //if(arr[j].DOB<pivotal)
        if(dob_cmp(arr[j].DOB,pivotal)==1)
        {
            i=i+1;
            swap(&arr[i],&arr[j]);
        }
    }

    swap(&arr[start],&arr[i]);
    return i;

}
void quicksort(record arr[],int start,int end)
{
    if(start<end)
    {
        int k=partition(arr,start,end);
        quicksort(arr,start,k-1);
        quicksort(arr,k+1,end);
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

    quicksort(r,0,n-1);

   /* for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%lf",r[i].reg,r[i].cred,r[i].gpa);
        printf("\n");
    }*/
    display(r,n);

    return 0;
}


