#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//insertion sort
void insertionsort(int arr[], int n) {

    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int key=arr[i];

        while(j>=0&&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

//merge sort
void merge(int arr[],int start,int mid,int end)
{
    int i=start;
    int j=mid+1;
    int k=0;
    int size=end-start+1;

    int* b=(int *)malloc(size*sizeof(int));

    while(i<=mid&&j<=end)
    {
        if(arr[i]<arr[j])
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

void mergesort(int arr[],int start,int end)
{
    if(start<end)
    {
        int mid=(start+end)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);

        merge(arr,start,mid,end);
    }
}


//heap sort

void heapify(int arr[],int n,int i)
{
    int max= i;
    int left=2 * i + 1;
    int right=2 * i + 2;

    if(left<n&&arr[left]>arr[max])
       max=left;

    if(right<n&&arr[right]>arr[max])
        max=right;

    if(max!=i) {
        int temp=arr[i];
        arr[i]=arr[max];
        arr[max]=temp;

        heapify(arr,n,max);
    }
}

void heapsort(int arr[],int n) {
    for(int i=(n/2)-1;i>=0;i--)
        heapify(arr, n, i);

    for(int i=n-1;i>0;i--){
        int temp = arr[0];
        arr[0]=arr[i];
        arr[i]=temp;

        heapify(arr, i, 0);
    }
}


//quick sort

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}


int partition(int arr[],int start,int end)
{
    int pivotal=arr[start];
    int i=start;

    for(int j=start+1;j<=end;j++)
    {
        if(arr[j]<pivotal)
        {
            i=i+1;
            swap(&arr[i],&arr[j]);
        }
    }

    swap(&arr[start],&arr[i]);
    return i;

}
void quicksort(int arr[],int start,int end)
{
    if(start<end)
    {
        int k=partition(arr,start,end);
        quicksort(arr,start,k-1);
        quicksort(arr,k+1,end);
    }
}

//counting sort

int max(int arr[],int n)
{
     int max=arr[0];

    for(int i=1;i<n;i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}


void countingsort(int a[],int n,int *b)
{
   int k=max(a,n);

  // int *c=(int*)malloc(k*sizeof(int));

  int c[k+1];
   for(int i=0;i<=k;i++){c[i]=0;}

   for(int i=0;i<n;i++)
   {
       c[a[i]]++;
   }

   for(int i=1;i<=k;i++)
   {
       c[i]=c[i]+c[i-1];
   }

   for(int i=n-1;i>=0;i--)
   {
       b[c[a[i]]-1]=a[i];
       c[a[i]]--;
   }

}





int main(){

    int N=10;
    int A[N];
    for(int i=0;i<N;i++){
        A[i]=rand()%N;
    }

    for(int i=0;i<N;i++){
        printf("%5d",A[i]);
    }


    int Arr1[N],Arr2[N],Arr3[N],Arr4[N],Arr5[N];
    for(int i=0;i<N;i++){
        Arr1[i]=A[i];
        Arr2[i]=A[i];
        Arr3[i]=A[i];
        Arr4[i]=A[i];
        Arr5[i]=A[i];
    }

   insertionsort(Arr1,N);
    printf("\nINSERTION SORT :\n");
    for(int i=0;i<N;i++){
        printf("%5d",Arr1[i]);
    }

   mergesort(Arr2,0,N-1);
    printf("\nMERGE SORT :\n");
    for(int i=0;i<N;i++){
        printf("%5d",Arr2[i]);
    }

    heapsort(Arr3,N);
    printf("\nHEAP SORT :\n");
    for(int i=0;i<N;i++){
        printf("%5d",Arr3[i]);
    }

    quicksort(Arr4,0,N-1);
    printf("\n QUICK SORT :\n");
    for(int i=0;i<N;i++){
        printf("%5d",Arr4[i]);
    }

    int B[N+1];
    countingsort(Arr5,N,B);
    printf("\n COUNTING SORT :\n");
    for(int i=0;i<N;i++){
        printf("%5d",B[i]);
    }

    
    return 0;
}
