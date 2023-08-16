#include<stdio.h>

int main(){
    int n,i,pos,num;
    printf("no.of elements in an array : \n");
    scanf("%d",&n);
    int ptr[n];
    printf("elements of an array : \n");
    for (i=0;i<n;i++){
        scanf("%d",&ptr[i]);
    }
    for (i=0;i<n;i++){
        printf("%d",ptr[i]);
        printf("\t");
    }
    printf("\n");
    printf("enter the number and position where you want to insert : \n");
    scanf("%d %d",&num,&pos);
    for (i=n-1;i>=pos;i--){
        ptr[i+1]=ptr[i];
    }
    ptr[pos]=num;
    n++;
    for (i=0;i<n;i++){
        printf("%d",ptr[i]);
        printf("\t");
    }
}