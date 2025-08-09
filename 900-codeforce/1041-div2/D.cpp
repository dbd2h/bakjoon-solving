#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MOD (long long)10e9+7;

using namespace std;

int compare(pair<int,int>p1,pair<int,int>p2)
{
    if(p1.first==p2.first) return p1.second<p2.second;
    return p1.first<p2.first;
}

void problem()
{
    int n,m;
    cin>>n>>m;

    vector<int> v[20001];
    int bit[200001]={0};
    for(int i=0;i<m;i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        v[n1].push_back(n2);
        v[n2].push_back(n1);
        bit[n1]++;
        bit[n2]++;
    }
    bool check[200001]={0};
    queue<pair<int,int>> q; // parent, child
    q.push({0,1});
    check[1]=true;
    while(!q.empty())
    {
        int parent=q.front().first;
        int num=q.front().second;
        q.pop();
        for(int i=0;i<bit[num];i++)
        {
            int next=v[num][i];
            if(check[next])
            {
                if(next==parent) continue;
                else
                {
                    cout<<0<<"\n";
                    return;
                }
            }
            check[next]=true;
            q.push({num,next});
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(check[i]) continue;
        cout<<0<<"\n";
        return;
    }
    int start=-1;
    for(int i=1;i<=n;i++)
    {
        if(bit[i]==1) continue;
        int c=0;
        for(int j=0;j<bit[i];j++)
        {
            if(bit[v[i][j]]==1) continue;
            c++;
        }
        if(c>2)
        {
            cout<<0<<"\n";
            return;
        }
        if(c==1 && start==-1)
        {
            start=i;
        }
    }
    long long res=2;
    if(start==-1)
    {
        for(long long i=1;i<=n-1;i++)
        {
            res*=i;
            res%=MOD;
        }
        cout<<res<<"\n";
        return;
    }
    res*=2;
    int bef=0;
    while(true)
    {
        int n1=-1;
        int n2=-1;
        for(int i=0;i<bit[start];i++)
        {
            int num=v[start][i];
            if(bit[num]!=1)
            {
                if(n1==-1)
                {
                    n1=num;
                    continue;
                }
                else if(n2==-1)
                {
                    n2=num;
                    continue;
                }
            }
        }
        if(bef==0)
        {
            for(long long i=1;i<=bit[start]-1;i++)
            {
                res*=i;
                res%=MOD;
            }
            bef=start;
            start=n1;
        }
        else if(n2!=-1)
        {
            for(long long i=1;i<=bit[start]-2;i++)
            {
                res*=i;
                res%=MOD;
            }
            if(n1==bef)
            {
                bef=start;
                start=n2;
            }
            else if(n2==bef)
            {
                bef=start;
                start=n1;
            }
        }
        else
        {
            for(long long i=1;i<=bit[start]-1;i++)
            {
                res*=i;
                res%=MOD;
            }
            break;
        }
    }
    cout<<res<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        problem();
    }
}