#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int count;
    cin>>count;
    cin.ignore();
    string s;
    stack<char> stack;
    int len;
    for(int i=0;i<count;i++)
    {
        getline(cin, s);
        s+="\n";
        len=s.length();
        for(int j=0;j<len;j++)
        {
            if(s[j]!=' '&&s[j]!='\n')
            {
                stack.push(s[j]);
            }
            else
            {
                while(!stack.empty())
                {
                    cout<<stack.top();
                    stack.pop();
                }
                cout<<' ';
            }
        }
        cout<<"\n";
    }
}