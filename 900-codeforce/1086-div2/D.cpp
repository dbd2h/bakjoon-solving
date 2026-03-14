#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
typedef long long ll;
typedef long double lld;

using namespace std;

void program()
{
    int n;
    cin>>n;
    int arr[500][500];
    bool isF=false;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<n;j++)
        {
            arr[i][j]=s[j]-'0';
            if(i==j && arr[i][j]==0)
            {
                isF=true;
            }
        }
    }
    if(isF)
    {
        cout<<"NO\n";
        return;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(i==j || j==k || i==k) continue;
                if(arr[j][i]==1 && arr[i][k]==1)
                {
                    if(arr[j][k]==0)
                    {
                        isF=true;
                        break;
                    }
                    arr[j][k]=0;
                } 
            }
            if(isF) break;
        }
        if(isF) break;
    }
    if(isF)
    {
        cout<<"NO\n";
        return;
    }
    int resCheck=0;
    int topo[500]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            if(arr[i][j])
            {
                topo[j]++;
                resCheck++;
            }
        }
    }
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(topo[i]==0) q.push(i);
    }
    int count=0;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        count++;
        for(int i=0;i<n;i++)
        {
            if(i==cur) continue;
            if(arr[cur][i]==0) continue;
            topo[i]--;
            if(topo[i]==0) q.push(i);
        }
    }
    if(count!=n) isF=true;
    int copyArr[500][500]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==1)
            {
                copyArr[j][i]=1;
                copyArr[i][j]=1;
            } 
        }
    }
    queue<int> bfsQ;
    bfsQ.push(0);
    bool check[500]={0};
    check[0]=1;
    while(!bfsQ.empty())
    {
        int cur=bfsQ.front();
        bfsQ.pop();
        for(int i=0;i<n;i++)
        {
            if(cur==i) continue;
            if(copyArr[cur][i]==0) continue;
            if(check[i]) continue;
            bfsQ.push(i);
            check[i]=1;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(check[i]==0)
        {
            isF=true;
        }
    }
    if(resCheck!=n-1 || isF)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            if(arr[i][j])
            {
                cout<<i+1<<" "<<j+1<<"\n";
            }
        }
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