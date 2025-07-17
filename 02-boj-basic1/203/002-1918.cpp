#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string s, finalS;
    cin>>s;
    stack<char> stack;
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        if(stack.empty()&&s[i]-'/'<=0)
        {
            stack.push(s[i]);
        }
        else if(s[i]=='(')
        {
            stack.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(stack.top()!='(')
            {
                finalS+=stack.top();
                stack.pop();
            }
            stack.pop();
        }
        else if(s[i]=='*'||s[i]=='/')
        {
            if(stack.top()!='+'&&stack.top()!='-'&&stack.top()!='(')
            {
                finalS+=stack.top();
                stack.pop();
            }
            stack.push(s[i]);
        }
        else if(s[i]=='+'||s[i]=='-')
        {
            while(!stack.empty())
            {
                if(stack.top()=='(')
                {
                    break;
                }
                finalS+=stack.top();
                stack.pop();
            }
            stack.push(s[i]);
            
        }
        else
        {
            finalS+=s[i];
        }
    }
    while(!stack.empty())
    {
        finalS+=stack.top();
        stack.pop();
    }
    cout<<finalS<<"\n";
}