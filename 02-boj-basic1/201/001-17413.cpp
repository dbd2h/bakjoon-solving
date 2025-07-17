#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string s, outS;
    getline(cin, s);
    s+='\n';
    int len=s.length();
    bool isTag=false;
    stack<char> stack;

    for(int i=0;i<len;i++)
    {
        if(s[i]=='<'&&!isTag)
        {
            while(!stack.empty())
            {
                outS+=stack.top();
                stack.pop();
            }
            isTag=true;
            outS+=s[i];
        }
        else if(s[i]=='>'&&isTag)
        {
            isTag=false;
            outS+=s[i];
        }
        else if(isTag)
        {
            outS+=s[i];
        }
        else if(s[i]==' '||s[i]=='\n')
        {
            while(!stack.empty())
            {
                outS+=stack.top();
                stack.pop();
            }
            outS+=' ';
        }
        else
        {
            stack.push(s[i]);
        }
    }
    cout<<outS<<"\n";
}