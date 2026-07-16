#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define MOD (ll)4294967296

using namespace std;

int moveArr[8][2]={{1,2},{2,1},{-1,2},{-2,1},{1,-2},{2,-1},{-1,-2},{-2,-1}};

vector<vector<ll>> v(64,vector<ll>(64,0));
vector<vector<ll>> matSq(64, vector<ll>(64,0));
vector<vector<ll>> mat(64, vector<ll>(64,0));

vector<vector<ll>> mulMat(vector<vector<ll>> v1, vector<vector<ll>> v2)
{
    vector<vector<ll>> retV(64,vector<ll>(64,0));
    for(int i=0;i<64;i++)
    {
        for(int j=0;j<64;j++)
        {
            ll cur=0;
            for(int k=0;k<64;k++)
            {
                cur+=v1[i][k]*(v2[k][j]/2);
                cur%=MOD;
                cur+=v1[i][k]*(v2[k][j]-v2[k][j]/2);
                cur%=MOD;
            }
            retV[i][j]=cur;
        }
    }
    return retV;
}

void recurF(int k)
{
    if(k==1) return;
    if(k%2==1)
    {
        recurF(k-1);
        matSq=mulMat(matSq,mat);
        for(int i=0;i<64;i++)
        {
            for(int j=0;j<64;j++)
            {
                v[i][j]+=matSq[i][j];
                v[i][j]%=MOD;
            }
        }
        return;
    }
    else
    {
        recurF(k/2);
        vector<vector<ll>> mulV=matSq;
        for(int i=0;i<64;i++)
        {
            mulV[i][i]++;
            mulV[i][i]%=MOD;
        }
        v=mulMat(v,mulV);
        matSq=mulMat(matSq,matSq);
        return;
    }
}

int main()
{
    int k;
    cin>>k;
    if(k==0)
    {
        cout<<1;
        return 0;
    }
    for(int x=0;x<8;x++)
    {
        for(int y=0;y<8;y++)
        {
            int cur=x*8+y;
            for(int k=0;k<8;k++)
            {
                int xp=x+moveArr[k][0];
                int yp=y+moveArr[k][1];
                if(xp<0 || xp>=8 || yp<0 || yp>=8) continue;
                int next=xp*8+yp;
                mat[cur][next]=1;
                matSq[cur][next]=1;
                v[cur][next]=1;
            }
        }
    }
    recurF(k);
    ll res=1;
    for(int i=0;i<64;i++)
    {
        res+=v[0][i];
        res%=MOD;
    }
    cout<<res;
}