#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 101
#define MOD (ll)(1e9+7)

using namespace std;

void mulMat(ll m1[LEN][LEN],ll m2[LEN][LEN], int n)
{
    ll retM[LEN][LEN];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ll num=0;
            for(int k=1;k<=n;k++)
            {
                num+=m1[i][k]*m2[k][j];
                num%=MOD;
            }
            retM[i][j]=num;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) m1[i][j]=retM[i][j];
    }
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    ll mat[LEN][LEN]={0};
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        mat[a][b]=1;
    }
    ll resM[LEN][LEN]={0};
    for(int i=1;i<=n;i++) resM[i][i]=1;
    while(k)
    {
        if(k%2==1) mulMat(resM,mat,n);
        mulMat(mat,mat,n);
        k/=2;
    }
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            res+=resM[i][j];
            res%=MOD;
        }
    }
    cout<<res;
}