#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>


typedef struct{
int x;
int y;
}pair;

void display(pair r[50])
{
    for(int i=0;i<50;i++)
    {
        printf("[%d,%d]",r[i].x,r[i].y);
        printf("\n");
    }
}

int max(pair arr[50])
{
     int max=arr[0].x;

    for(int i=1;i<50;i++) {
        if (arr[i].x > max)
            max = arr[i].x;
    }
    return max;
}


void countingsort(pair a[50],pair *b)
{
   int k=max(a);
 
  int c[k+1];
   for(int i=0;i<=k;i++){c[i]=0;}

   for(int i=0;i<50;i++)
   {
       c[a[i].x]++;
   }

   for(int i=1;i<=k;i++)
   {
       c[i]=c[i]+c[i-1];
   }

   for(int i=50-1;i>=0;i--)
   {
       b[c[a[i].x]-1]=a[i];
       c[a[i].x]--;
   }

}

int main()
{

    pair l[50];

    for(int i=0;i<50;i++)
    {
         l[i].x=rand()%25;
         l[i].y=i+1;
    }

    display(l);
    printf("\n\n");

   pair b[50];
   countingsort(l,b);
    display(b);

    return 0;
}
