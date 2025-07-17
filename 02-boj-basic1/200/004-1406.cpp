#include <iostream>
#include <stack>
#include <string>

using namespace std;

void lfunc(stack<char> &l, stack<char> &r)
{
    if(l.empty())
    {
        return;
    }
    char c=l.top();
    l.pop();
    r.push(c);
}

void dfunc(stack<char> &l, stack<char> &r)
{
    if(r.empty())
    {
        return;
    }
    char c=r.top();
    r.pop();
    l.push(c);
}

void bfunc(stack<char> &l)
{
    if(l.empty())
    {
        return;
    }
    l.pop();
}

void pfunc(stack<char> &l, char word)
{
    l.push(word);
}

int main()
{
    string s;
    cin>>s;
    stack<char> s1;
    stack<char> s2;
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        s1.push(s[i]);
    }
    int count;
    cin>>count;
    char command;
    for(int i=0;i<count;i++)
    {
        cin>>command;

        if(command=='L')
        {
            lfunc(s1,s2);
        }
        else if(command=='D')
        {
            dfunc(s1,s2);
        }
        else if(command=='B')
        {
            bfunc(s1);
        }
        else if(command=='P')
        {
            char c;
            cin>>c;
            pfunc(s1,c);
        }
    }
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    while(!s2.empty())
    {
        cout<<s2.top();
        s2.pop();
    }
    cout<<"\n";
}