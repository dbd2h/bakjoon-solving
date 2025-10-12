#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    cin>>m;
    int arr[200001][20];

    for(int i=1;i<=m;i++)
    {
        cin>>arr[i][0];
    }
    for(int i=1;i<20;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int next=arr[j][i-1];
            arr[j][i]=arr[next][i-1];
        }
    }


    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int n,x;
        cin>>n>>x;
        stack<bool> st;
        while(n)
        {
            st.push(n%2);
            n/=2;
        }
        while(!st.empty())
        {
            int cur=st.top();
            st.pop();
            int size=st.size();
            if(cur)
            {
                x=arr[x][size];
            }
        }
        cout<<x<<"\n";
    }
}