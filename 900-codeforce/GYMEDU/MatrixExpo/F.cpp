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
#define INF ((ll)(1e18)+7)

using namespace std;

struct MATRIX
{
    vector<vector<ll>> v;
    MATRIX(): v(LEN,vector<ll>(LEN,INF)) {}
    
    void cal(MATRIX &m2, int n)
    {
        vector<vector<ll>> resV(LEN,vector<ll>(LEN,INF));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                ll res=INF;
                for(int k=1;k<=n;k++)
                {
                    if(v[i][k]==INF || m2.v[k][j]==INF) continue;
                    res=min(res,v[i][k]+ m2.v[k][j]);
                }
                resV[i][j]=res;
            }
        }
        v=resV;
    }
};

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    MATRIX resM,mat;
    for(int i=0;i<m;i++)
    {
        int a,b;
        ll w;
        cin>>a>>b>>w;
        mat.v[a][b]=w;
    }
    for(int i=1;i<=n;i++) resM.v[i][i]=0;
    while(k)
    {
        if(k%2==1) resM.cal(mat,n);
        mat.cal(mat,n);
        k/=2;
    }
    ll res=INF;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(resM.v[i][j]==INF) continue;
            res=min(res,resM.v[i][j]);
        }
    }
    if(res==INF) cout<<"IMPOSSIBLE";
    else cout<<res;
}