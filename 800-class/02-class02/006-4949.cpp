#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string s;
    getline(cin,s);
    while(s!=".")
    {
        int len=s.size();
        stack<char> st;
        bool isYes=true;
        for(int i=0;i<len;i++)
        {
            if(i==len-1)
            {
                if(s[i]!='.' || !st.empty())
                {
                    isYes=false;
                }
                break;
            }
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') st.push(s[i]);
            else if(s[i]==')')
            {
                if(!st.empty() && st.top()=='(') st.pop();
                else
                {
                    isYes=false;
                    break;
                }
            }
            else if(s[i]==']')
            {
                if(!st.empty() && st.top()=='[') st.pop();
                else
                {
                    isYes=false;
                    break;
                }
            }
            else if(s[i]=='}')
            {
                if(!st.empty() && st.top()=='{') st.pop();
                else
                {
                    isYes=false;
                    break;
                }
            }
        }
        if(isYes) cout<<"yes\n";
        else cout<<"no\n";
        getline(cin,s);
    }

}