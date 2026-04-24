#include <iostream>
#include <stack>

using namespace std;

void problem()
{
    int n;
    cin>>n;
    int choice[100001];
    for(int i=1;i<=n;i++)
    {
        cin>>choice[i];
    }
    int check[100001]={0};
    bool isCycle[100001]={0};
    for(int i=1;i<=n;i++)
    {
        if(check[i]) continue;
        stack<int> st;
        st.push(i);
        check[i]=i;
        while(!st.empty())
        {
            int cur=st.top();
            int next=choice[cur];
            if(check[next]==0)
            {
                check[next]=i;
                st.push(next);
                continue;
            }
            else if(check[next]!=i)
            {
                break;
            }
            isCycle[next]=1;
            while(cur!=next)
            {
                isCycle[cur]=1;
                st.pop();
                if(st.empty()) break;
                cur=st.top();
            }
            break;
        }
    }
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(isCycle[i]==0) res++;
    }
    cout<<res<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++) problem();
}