#include<iostream>
using namespace std;

char st[100];
int top=-1;

void push(char c)
{
    top++;
    st[top]=c;
}

char pop()
{
    char c=st[top];
    top--;
    return c;
}

char peek()
{
    return st[top];
}

int precedence(char c)
{
    if(c=='+' || c=='-')
        return 1;

    if(c=='*' || c=='/')
        return 2;

    return 0;
}
