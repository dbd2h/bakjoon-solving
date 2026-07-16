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

using namespace std;

int cross[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int main()
{
    int n,q;
    cin>>n>>q;
    int bit[LEN][LEN]={0};
    int x=1;
    int y=1;
    for(int i=0;i<q;i++)
    {
        char a;
        int b,d;
        cin>>a>>b;
        if(a=='N') d=0;
        else if(a=='S') d=1;
        else if(a=='E') d=2;
        else if(a=='W') d=3;
        for(int j=1;j<=b;j++)
        {
            int xp=x+cross[d][0];
            int yp=y+cross[d][1];
            if(xp<=0 || xp>n || yp<=0 || yp>n) break;
            bit[xp][yp]+=1;
            x=xp;
            y=yp;
        }
    }
    int res=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(bit[i][j]>=2) res++;
        }
    }
    cout<<res;
}