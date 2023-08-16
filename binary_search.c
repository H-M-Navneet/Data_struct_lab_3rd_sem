#include<stdio.h>
#include<stdlib.h>

int search(int a[],int key,int low,int high)
{
    if(low>high)
    {
        return -1;
    }
    int mid;
    mid = (low+high)/2;
    if(key==a[mid])
    {
        return mid;
    }
    else if(key<a[mid])
    {
        return search(a,key,low,(mid-1));
    }
    else if(key>a[mid])
    {
        return search(a,key,(mid+1),high);
    }
}
void main()
{
    int *a,n,res,p,key;
    printf("enter no.of elements in an array\n");
    scanf("%d",&n);
    a = (int *)malloc(n*sizeof(int));
    printf("enter value : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",(a+i));
    }
    p=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<a[i+1])
        {
            p++;
        }
    }
    if(p==n-1)
    {
        printf("sorted\n");
    }
    else
    {
        printf("not sorted\n");
        return;
    }
    printf("enter the key to be searched\n");
    scanf("%d",&key);
    res = search(a,key,0,(n-1));
    if(res==-1)
    {
        printf("element not found\n");
    }
    else
    {
        printf("element found at position %d",res+1);
    }
}