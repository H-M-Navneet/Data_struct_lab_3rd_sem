#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int stack[20];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char exp[20];
    char *e;
    int n1,n2,n3,num;
    printf("enter the postfix expression : \n");
    scanf("%s",exp);
    e = exp;
    while(*e!='\0')
    {
        if(isdigit(*e))
        {
            num = *e - '0';
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(*e)
            {
                case '+':
                {
                    n3 = n1 + n2;
                    push(n3);
                    break;
                }
                case '-':
                {
                    n3 = n1 - n2;
                    push(n3);
                    break;
                }
                case '*':
                {
                    n3 = n1 * n2;
                    push(n3);
                    break;
                }
                case '/':
                {
                    n3 = n1/n2;
                    push(n3);
                    break;
                }
            }
        }
        e++;
    }
    printf("result = %d",pop());
    return 0;
}