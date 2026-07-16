#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define MOD (ll)(1e9+7)

using namespace std;

struct MATRIX
{
    vector<vector<ll>> mat;
    MATRIX(): mat(201, vector<ll>(201,0)) {};
    void product(MATRIX &m1, MATRIX &m2, int n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                ll num=0;
                for(int k=1;k<=n;k++)
                {
                    num+=m1.mat[i][k]*m2.mat[k][j];
                    num%=MOD;
                }
                mat[i][j]=num;
            }
        }
    }
};

struct V
{
    vector<ll> v;
    V(): v(201,0){};
    void product(MATRIX &m, int n)
    {
        vector<ll> retV(201);
        for(int i=1;i<=n;i++)
        {   
            ll num=0;
            for(int j=1;j<=n;j++)
            {
                num+=v[j]*m.mat[j][i];
                num%=MOD;
            }
            retV[i]=num;
        }
        for(int i=1;i<=n;i++)
        {
            v[i]=retV[i];
        }
    }
};

MATRIX bit[32];

int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        bit[0].mat[a][b]=1;
    }
    ll num=2;
    int idx=1;
    while(num<MOD)
    {
        bit[idx].product(bit[idx-1],bit[idx-1],n);
        num*=2;
        idx++;
    }
    for(int i=0;i<q;i++)
    {
        int s,t,k;
        cin>>s>>t>>k;
        V resV;
        resV.v[s]=1;
        int idx=0;
        while(k)
        {
            if(k%2==1) resV.product(bit[idx],n);
            k/=2;
            idx++;
        }
        cout<<resV.v[t]<<"\n";
    }
}