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
#define LEN 20001
#define INF (ll)(1e18)

using namespace std;

void program()
{
    int x,y;
    cin>>x>>y;
    ll sumV=0;
    int len=0;
    for(int i=1;i<=LEN;i++)
    {
        ll cur=sumV+i;
        if(x+y<cur) break;
        sumV=cur;
        len++;
    }
    ll mi=x+y-sumV;
    int xp=x-mi/2;
    int yp=y-mi/2;
    if(mi%2==1)
    {
        xp--;
    }
    int resArr[LEN];
    for(int i=0;i<len;i++)
    {
        int cur=len-i;
        if(xp>=cur)
        {
            resArr[i]=0;
            xp-=cur;
        }
        else resArr[i]=1;
    }
    for(int i=0;i<len;i++)
    {
        if(resArr[i]==0) cout<<'X';
        else cout<<'Y';
    }
    cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}