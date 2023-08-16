#include<stdio.h>

void tower(int n,char src,char dest,char aux)
{
    if(n==1)
    {
        printf("disk 1 moved from rod %c to %c\n",src,dest);
        return;
    }
    tower(n-1,src,aux,dest);
    printf("disk %d moved from rod %c to %c\n",n,src,dest);
    tower(n-1,aux,src,dest);
}
void main()
{
    int n;
    printf("no.of disks\n");
    scanf("%d",&n);
    printf("moves made\n");
    tower(n,'A','B','C');
}