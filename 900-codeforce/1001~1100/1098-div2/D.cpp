#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

#define LEN 2000001

using namespace std;

vector<int> pos[LEN];
int sumArr[LEN];
int bit[LEN];
int len[LEN];

void program(int t)
{
    int n;
    cin>>n;
    int maxY2=0;
    int minY2=n+1;
    for(int i=0;i<=n;i++)
    {
        bit[i]=0;
        len[i]=0;
    }
    if(t>0)
    {
        for(int i=0;i<=n;i++) pos[i].clear();
    }
    sumArr[0]=0;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        pos[a].push_back(b);
        bit[b]++;
        len[a]++;
        if(maxY2<b) maxY2=b;
        if(minY2>b) minY2=b;
    }
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        sumArr[i]=sumArr[i-1];
        if(bit[i]==0) continue;
        sumArr[i]+=1;
    }
    int maxY1=0;
    int minY1=n;
    for(int i=1;i<=n;i++)
    {
        if(len[i]==0) continue;
        for(int y : pos[i])
        {
            bit[y]--;
            if(maxY1<y) maxY1=y;
            if(minY1>y) minY1=y;
        }
        while(maxY2>minY2 && bit[maxY2]==0) maxY2--;
        while(maxY2>minY2 && bit[minY2]==0) minY2++;
        if(maxY2<=minY2) break;
        ll num=sumArr[min(maxY2,maxY1)]-sumArr[max(minY1,minY2)];
        if(num<=0) continue;
        res+=num;
    }
    cout<<res<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program(t);
    }
}
