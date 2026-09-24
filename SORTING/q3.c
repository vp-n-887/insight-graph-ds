#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>


typedef struct{
int x1;
int y1;
int x2;
int y2;
int dis;
}line;

line getdata()
{
    line r;
    scanf("%d%d%d%d",&r.x1,&r.y1,&r.x2,&r.y2);
    r.dis=sqrt(((r.x2-r.x1)*(r.x2-r.x1))+((r.y2-r.y1)*(r.y2-r.y1)));
    return r;
}

void display(line r[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("[%d,%d]\t[%d,%d]----%d",r[i].x1,r[i].y1,r[i].x2,r[i].y2,r[i].dis);
        printf("\n");
    }
}

void heapify(line arr[],int n,int i)
{
    int max= i;
    int left=2 * i + 1;
    int right=2 * i + 2;

    if(left<n&&arr[left].dis>arr[max].dis)
       max=left;

    if(right<n&&arr[right].dis>arr[max].dis)
        max=right;

    if(max!=i) {
        line temp=arr[i];
        arr[i]=arr[max];
        arr[max]=temp;

        heapify(arr,n,max);
    }
}

void heapsort(line arr[],int n) {
    for(int i=(n/2)-1;i>=0;i--)
        heapify(arr, n, i);

    for(int i=n-1;i>0;i--){
        line temp = arr[0];
        arr[0]=arr[i];
        arr[i]=temp;

        heapify(arr, i, 0);
    }
}

int main()
{
    int n;
    scanf("%d",&n);

    line l[n];

    for(int i=0;i<n;i++)
    {
         l[i]=getdata();
    }

    heapsort(l,n);

   /* for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%lf",r[i].reg,r[i].cred,r[i].gpa);
        printf("\n");
    }*/
    display(l,n);

    return 0;
}




