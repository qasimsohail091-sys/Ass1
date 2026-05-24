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

int main()
{
    string infix, postfix="";
    cout<<"Enter Expression: ";
    getline(cin,infix);

    for(int i=0;i<infix.length();i++)
    {
        char ch=infix[i];

        if(ch==' ')
            continue;

        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
        {
            postfix+=ch;
            postfix+=' ';
        }

        else if(ch=='(' || ch=='[' || ch=='{')
        {
            push(ch);
        }

        else if(ch==')' || ch==']' || ch=='}')
        {
            while(top!=-1 && peek()!='(' && peek()!='[' && peek()!='{')
            {
                postfix+=pop();
                postfix+=' ';
            }

            pop();
        }

        else
        {
            while(top!=-1 && precedence(peek())>=precedence(ch))
            {
                postfix+=pop();
                postfix+=' ';
            }

            push(ch);
        }
    }

    while(top!=-1)
    {
        postfix+=pop();
        postfix+=' ';
    }

    cout<<"Postfix: "<<postfix<<endl;
