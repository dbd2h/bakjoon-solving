#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

ll MOD=1'000'003;

ll mulArr[40][50][50]={0};

void mulMaker(int c, ll t, ll cur, int n)
{
    if(t<cur) return;
    if(c==0)
    {
        mulMaker(c+1, t, cur*2,n);
        return;
    }
    for(int i=0;i<n*5;i++)
    {
        for(int j=0;j<n*5;j++)
        {
            ll sum=0;
            for(int k=0;k<n*5;k++)
            {
                sum+=mulArr[c-1][i][k]*mulArr[c-1][k][j];
                sum%=MOD;
            }
            mulArr[c][i][j]=sum;
        }
    }
    mulMaker(c+1,t,cur*2,n);
}

void resultMaker(int c, ll t, int n, ll result[50][50])
{
    if(t==1)
    {
        for(int i=0;i<n*5;i++)
        {
            for(int j=0;j<n*5;j++)
            {
                result[i][j]=mulArr[c][i][j];
            }
        }
        return;
    }
    resultMaker(c+1,t/2,n,result);
    if(t%2==0) return;
    ll resC[50][50];
    for(int i=0;i<n*5;i++)
    {
        for(int j=0;j<n*5;j++)
        {
            ll sum=0;
            for(int k=0;k<n*5;k++)
            {
                sum+=result[i][k]*mulArr[c][k][j];
                sum%=MOD;
            }
            resC[i][j]=sum;
        }
    }
    for(int i=0;i<n*5;i++)
    {
        for(int j=0;j<n*5;j++)
        {
            result[i][j]=resC[i][j];
        }
    }
}

int main()
{
    int n,s,e,t;
    cin>>n>>s>>e>>t;
    ll graph[50][50]={0};
    ll res[50][50]={0};
    for(int i=0;i<n*5;i++)
    {
        if(i%5==0) continue;
        graph[i][i-1]=1;
    }
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<s.size();j++)
        {
            int cur=s[j]-'0';
            if(cur==0) continue;
            graph[i*5][j*5+cur-1]=1;
        }
    }
    for(int i=0;i<n*5;i++)
    {
        for(int j=0;j<n*5;j++)
        {
            mulArr[0][i][j]=graph[i][j];
        }
    }
    mulMaker(0,(ll)t,1,n);
    ll result[50][50]={0};
    resultMaker(0,t,n,result);
    cout<<result[(s-1)*5][(e-1)*5];
}