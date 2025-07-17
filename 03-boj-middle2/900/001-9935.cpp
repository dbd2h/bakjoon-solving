#include <iostream>
#include <string>
#include <stack>

using namespace std;

void stackToString(string &result, stack<char> &st, stack<int> &nst)
{
    stack<char> revst;
    int n=st.size();
    for(int i=0;i<n;i++)
    {
        revst.push(st.top());
        st.pop();
    }
    n=revst.size();
    for(int i=0;i<n;i++)
    {
        result+=revst.top();
        revst.pop();
    }
    n=nst.size();
    for(int i=0;i<n;i++)
    {
        nst.pop();
    }
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    string result;
    stack<char> st;
    stack<int> nst;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]!=s2[0] && (st.empty() || s1[i]!=s2[nst.top()]))
        {
            if(!st.empty()) stackToString(result, st, nst);
            result+=s1[i];
            continue;
        }
        
        if(!nst.empty() && s1[i]==s2[nst.top()])
        {
            st.push(s1[i]);
            int t=nst.top();
            nst.pop();
            nst.push(t+1);
            if(nst.top()==s2.size())
            {
                for(int i=0;i<s2.size();i++)
                {
                    st.pop();
                }
                nst.pop();
            }
            continue;
        }
        if(s1[i]==s2[0])
        {
            st.push(s1[i]);
            nst.push(1);
            if(s2.size()==1)
            {
                st.pop();
                nst.pop();
            }
            continue;
        }
    }
    if(!st.empty())
    {
        stackToString(result, st, nst);
    }
    if(result.size()==0) result="FRULA";
    cout<<result;
}