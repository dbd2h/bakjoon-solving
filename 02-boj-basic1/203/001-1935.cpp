#include <iostream>
#include <stack>
#include <string>

using namespace std;

void stackCal(double *a, double *b, stack<double> &stack)
{
    *b=stack.top();
    stack.pop();
    *a=stack.top();
    stack.pop();
}

int main()
{
    int count;
    cin>>count;
    int alpha[count];
    string s;
    cin>>s;
    for(int i=0;i<count;i++)
    {
        cin>>alpha[i];
    }
    stack<double> stack;
    int len=s.length();
    double a;
    double b;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
        {
            stackCal(&a,&b,stack);
            if(s[i]=='+')
                stack.push(a+b);
            else if(s[i]=='-')
                stack.push(a-b);
            else if(s[i]=='*')
                stack.push(a*b);
            else if(s[i]=='/')
                stack.push(a/b);
        }
        else
        {
            stack.push(alpha[s[i]-'A']);
        }
    }
    cout<<fixed;
    cout.precision(2);
    cout<<stack.top()<<"\n";
}