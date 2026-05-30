#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

void program()
{
    int n,m;
    cin>>n>>m;
    vector<int> v;
    v.resize(m+1);
    vector<int> inputV[n+1];
    for(int i=1;i<=m;i++)
    {
        v[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        for(int j=0;j<num;j++)
        {
            int a;
            cin>>a;
            v[a]++;
            inputV[i].push_back(a);
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(!v[i])
        {
            cout<<"NO\n";
            return;
        }
    }
    int rem=0;
    for(int i=0;i<n;i++)
    {
        bool isR=1;
        for(int j=0;j<inputV[i].size();j++)
        {
            int cur=inputV[i][j];
            if(v[cur]==1)
            {
                isR=false;
                break;
            }
        }
        if(isR) rem++;
    }
    if(rem>=2)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
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