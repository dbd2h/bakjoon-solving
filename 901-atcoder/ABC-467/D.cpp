#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
typedef long long ll;
typedef long double lld;

using namespace std;

void problem()
{
    __int128 x[4],y[4];
    for(int i=0;i<4;i++)
    {
        ll num;
        cin>>num;
        x[i]=num;
        cin>>num;
        y[i]=num;
    }
    __int128 c1[3],c2[3];
    c1[0]=x[0]*2-x[1]*2;
    c1[1]=y[0]*2-y[1]*2;
    c1[2]=x[1]*x[1]+y[1]*y[1]-(x[0]*x[0]+y[0]*y[0]);
    c2[0]=x[2]*2-x[3]*2;
    c2[1]=y[2]*2-y[3]*2;
    c2[2]=x[3]*x[3]+y[3]*y[3]-(x[2]*x[2]+y[2]*y[2]);
    if(c1[0]*c2[1]!=c1[1]*c2[0])
    {
        cout<<"Yes\n";
        return;
    }
    if(c1[0]*c2[2]==c1[2]*c2[0] && c1[1]*c2[2]==c1[2]*c2[1])
    {
        cout<<"Yes\n";
        return;
    }
    cout<<"No\n";
    
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++) problem();
}