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

int main()
{
    ll n;
    cin>>n;
    ll mat[2][2]={{20,6},{7,19}};
    ll res[2]={0,1};
    while(n)
    {
        if(n%2==1)
        {
            ll copyRes[2]={0};
            for(int i=0;i<2;i++)
            {
                for(int j=0;j<2;j++)
                {
                    copyRes[i]+=res[j]*mat[j][i];
                    copyRes[i]%=MOD;
                }
            }
            for(int i=0;i<2;i++) res[i]=copyRes[i];
        }
        ll copyRes[2][2]={0};
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                copyRes[i][j]+=mat[i][0]*mat[0][j];
                copyRes[i][j]%=MOD;
                copyRes[i][j]+=mat[i][1]*mat[1][j];
                copyRes[i][j]%=MOD;
            }
        }
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++) mat[i][j]=copyRes[i][j];
        }
        n/=2; 
    }
    cout<<res[1];
}