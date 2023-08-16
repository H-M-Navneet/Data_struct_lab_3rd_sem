#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char pop(char*,int*);
void push(char*,char,int*);
void operator(char,char*,char*,int*,int*);
char peek(char*,int*);
void dump(char*,char*,int*,int*);

int main()
{
    int stop=-1,ptop=-1;
    char* infix;
    infix = (char*)malloc(50*sizeof(char));
    printf("enter a infix expression : \n");
    scanf("%s",infix);
    infix = realloc(infix,strlen(infix)*sizeof(char));
    char* postfix;
    postfix = (char*)malloc(strlen(infix)*sizeof(char));
    char* stack;
    stack = (char*)malloc(strlen(infix)*sizeof(char));
    for(int i=0;i<strlen(infix);i++)
    {
        operator(infix[i],stack,postfix,&stop,&ptop);
    }
    dump(stack,postfix,&stop,&ptop);
    printf("%s\n",postfix);
}

void operator(char c,char* st,char *po,int* stop,int* ptop)
{
    if(isalpha(c)||isdigit(c))
    {
        push(po,c,ptop);
    }
    else if(c=='(')
    {
        push(st,c,stop);
    }
    else if(c==')')
    {
        while(1)
        {
            char p;
            p=pop(st,stop);
            if(p=='(')
            {
                break;
            }
            push(po,p,ptop);
        }
    }
    else if(c=='+'||c=='-')
    {
        char p;
        p=peek(st,stop);
        if(p=='*'||p=='/'||p=='%'||p=='+'||p=='-')
        {
            pop(st,stop);
            operator(c,st,po,stop,ptop);
        }
        else
        {
            push(st,c,stop);
        }
    }
    else if(c=='*'||c=='/'||c=='%')
    {
        char p;
        p=peek(st,stop);
        if(p=='*'||p=='/'||p=='%')
        {
            pop(st,stop);
            operator(c,st,po,stop,ptop);
        }
        else
        {
            push(st,c,stop);
        }
    }
}

void push(char* po,char c,int* ptop)
{
    (*ptop)++;
    po[*ptop] = c;
}

char pop(char* st,int* stop)
{
    int r;
    r = st[*stop];
    (*stop)--;
    return r;
}

char peek(char* po,int* ptop)
{
    int x;
    x = po[*ptop];
    return x;
}

void dump(char* st,char* po,int* stop,int *ptop)
{
    while(*stop!=-1)
    {
        po[++(*ptop)] = st[*stop];
        (*stop)--;
    }
}