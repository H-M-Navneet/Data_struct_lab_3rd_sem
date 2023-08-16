#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employees{
        char name[30];
        int id;
        char dept[30];
        float salary;
};

void total_salary();

int n;
struct employees* e;

void main()
{
        printf("no.of employees : \n");
        scanf("%d",&n);
        e = (struct employees*)malloc(n*sizeof(struct employees));
        for(int i=0;i<n;i++)
        {
                printf("enter name of employee %d : \n",i+1);
                scanf("%s",(e+i)->name);
                printf("enter ID of employee %d : \n",i+1);
                scanf("%d",&(e+i)->id);
                printf("enter department of employee %d : \n",i+1);
                scanf("%s",(e+i)->dept);
                printf("enter salary of employee %d : \n",i+1);
                scanf("%f",&(e+i)->salary);
        }
        total_salary();
}

void total_salary()
{
        char dept[30];
        float total=0;
        printf("enter the department name : \n");
        scanf("%s",dept);
        for(int i=1;i<=n;i++)
        {
                if (strcmp((e+i)->dept,dept)==0)
                {
                        total = total + ((e+i)->salary);
                }
        }
        printf("Total salary : %f\n",total);
}