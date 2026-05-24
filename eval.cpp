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

    int values[26];

    for(int i=0;i<26;i++)
        values[i]=-1;

    for(int i=0;i<postfix.length();i++)
    {
        char ch=postfix[i];

        if(ch>='a' && ch<='z')
        {
            if(values[ch-'a']==-1)
            {
                cout<<"Enter "<<ch<<" value: ";
                cin>>values[ch-'a'];
            }
        }
    }

    int st2[100];
    int top2=-1;

    for(int i=0;i<postfix.length();i++)
    {
        char ch=postfix[i];

        if(ch==' ')
            continue;

        if(ch>='0' && ch<='9')
        {
            top2++;
            st2[top2]=ch-'0';
        }

        else if(ch>='a' && ch<='z')
        {
            top2++;
            st2[top2]=values[ch-'a'];
        }

        else
        {
            int b=st2[top2];
            top2--;

            int a=st2[top2];
            top2--;

            int ans;

            if(ch=='+')
                ans=a+b;

            else if(ch=='-')
                ans=a-b;

            else if(ch=='*')
                ans=a*b;

            else
                ans=a/b;

            top2++;
            st2[top2]=ans;
        }
    }

    cout<<"Result = "<<st2[top2];

    return 0;
}
