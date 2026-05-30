#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

void program()
{
    int n;
    cin>>n;
    long long arr[400004];
    for(int i=0;i<n*2;i++)
    {
        cin>>arr[i];
    }
    long long tot=0;
    for(int i=0;i<n;i++)
    {
        tot+=((long long) arr[n*2-i-1]-(long long) arr[i]);
    }
    long long minus=0;
    stack<long long> st;
    for(int i=n;i>0;i--)
    {
        tot-=minus*(long long)2;
        st.push(tot);
        minus=(arr[n*2-i]-arr[i-1])-minus;
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}