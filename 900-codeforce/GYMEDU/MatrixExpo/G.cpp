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
    vector<vector<ll>> v;
    MATRIX(): v(13,vector<ll>(13,0)){};
    
    void product(MATRIX &mat, int n)
    {
        vector<vector<ll>> retM(13,vector<ll>(13,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ll num=0;
                for(int k=0;k<n;k++)
                {
                    num+=v[i][k]*mat.v[k][j];
                    num%=MOD;
                }
                retM[i][j]=num;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                v[i][j]=retM[i][j];
            }
        }
    }
};

int main()
{
    int n;
    ll k;
    cin>>n>>k;
    ll res=0;
    MATRIX resM;
    for(int i=n-1;i>=0;i--)
    {
        ll num;
        cin>>num;
        resM.v[0][i]=num;
    }
    MATRIX mat;
    for(int i=0;i<n;i++)
    {
        ll num;
        cin>>num;
        mat.v[i][0]=num;
    }
    for(int i=0;i<n-1;i++)
    {
        mat.v[i][i+1]=1;
    }
    ll p,q,r;
    cin>>p>>q>>r;
    if(k<n)
    {
        int idx=n-k-1;
        cout<<resM.v[0][idx];
        return 0;
    }
    mat.v[n][0]=p;
    mat.v[n+1][0]=q;
    mat.v[n+2][0]=r;
    mat.v[n][n]=1;
    mat.v[n][n+1]=1;
    mat.v[n][n+2]=1;
    mat.v[n+1][n+1]=1;
    mat.v[n+1][n+2]=2;
    mat.v[n+2][n+2]=1;
    resM.v[0][n]=1;
    resM.v[0][n+1]=n;
    resM.v[0][n+2]=n*n;
    k-=(n-1);
    while(k)
    {
        if(k%2==1)
        {
            resM.product(mat,n+3);
        }
        mat.product(mat,n+3);
        k/=2;
    }
    res+=resM.v[0][0];
    res%=MOD;
    cout<<res;
}