#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin>>n;
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        if(num==0) st.pop();
        else st.push(num);
    }
    int len=st.size();
    long long res=0;
    for(int i=0;i<len;i++)
    {
        res+=(long long)st.top();
        st.pop();
    }
    cout<<res;
}