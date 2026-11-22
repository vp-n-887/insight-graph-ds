#include<stdio.h>

int linear(int a[],int k)
{
    for(int i=0;i<8;i++)
    {
        if(a[i]==k){return i;}
    }
    return -1;
}

int binary(int n,int a[],int k)
{
    int start=0;
    int end=n-1;
    
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(a[mid]==k){return mid;}
        
        if(k<a[mid]){end=mid-1;}
        else{start=mid+1;}
    }
    
    return -1;
}

int main()
{
    int a[]={1,2,3,4,5,6,7,100};
    
    printf("%d",linear(a,5));
    printf("%d",binary(8,a,5));
    
}