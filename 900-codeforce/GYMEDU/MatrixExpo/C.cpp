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

void mulMat(ll m1[2][2],ll m2[2][2])
{
    ll retM[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            ll res=0;
            for(int k=0;k<2;k++)
            {
                res+=m1[i][k]*m2[k][j];
                res%=MOD;
            }
            retM[i][j]=res;
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++) m1[i][j]=retM[i][j];
    }
}

int main()
{
    ll n;
    cin>>n;
    ll res[2][2]={{0,1},{0,0}};
    ll mat[2][2]={{0,1},{1,1}};
    while(n)
    {
        if(n%2==1) mulMat(res,mat);
        mulMat(mat,mat);
        n/=2;
    }
    cout<<res[0][0];
}