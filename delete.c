#include<stdio.h>

int main(){
    int n,i,pos;
    printf("enter the no.of elements in an array : \n");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements of an array : \n");
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("array before deletion : \n");
    for (i=0;i<n;i++){
        printf("%d",a[i]);
        printf("\t");
    }
    printf("\n");
    printf("enter the position which you want to delete : \n");
    scanf("%d",&pos);
    for (i=pos-1;i<n-1;i++){
        a[i]=a[i+1];
    }
    n--;
    printf("array after deletion : \n");
    for (i=0;i<n;i++){
        printf("%d \t",a[i]);
    }
}