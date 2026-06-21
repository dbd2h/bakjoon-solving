#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

#define LEN 100001

using namespace std;

vector<int> graph[LEN];
ll dp[LEN];
ll up[LEN];
vector<int> leap;
int n;
ll m;

void dfsDp(int cur, int parent)
{
    ll res=1;
    bool isLeap=true;
    for(auto &next : graph[cur])
    {
        if(parent==next) continue;
        dfsDp(next, cur);
        isLeap=false;
        res*=(dp[next]+1);
        res%=m;
    }
    dp[cur]=res;
}

void dfsUp(int cur, int parent)
{
    vector<int> v;
    for(auto &next : graph[cur])
    {
        if(next==parent) continue;
        v.push_back(next);
    }
    int len=v.size();
    vector<ll> pre(len);
    vector<ll> suf(len);
    if(len==0) return;
    ll res1=1;
    ll res2=1;
    for(int i=0;i<len;i++)
    {
        int j=len-1-i;
        if(i!=0)
        {
            res1=pre[i-1];
            res2=suf[j+1];
        }
        res1*=(dp[v[i]]+1);
        res1%=m;
        res2*=(dp[v[j]]+1);
        res2%=m;
        pre[i]=res1;
        suf[j]=res2;
    }
    for(int i=0;i<len;i++)
    {
        int next=v[i];
        ll res=up[cur];
        if(i!=0)
        {
            res*=pre[i-1];
            res%=m;
        } 
        if(i!=(len-1))
        {
            res*=suf[i+1];
            res%=m;
        } 
        res+=1;
        res%=m;
        up[next]=res;
        dfsUp(next,cur);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfsDp(1,0);
    up[1]=1;
    dfsUp(1,0);
    for(int i=1;i<=n;i++)
    {
        ll res=dp[i];
        res*=up[i];
        res%=m;
        cout<<res<<"\n";
    }
}

// 1. dp[i]: 1번째 노드가 루트인 트리에서 i번째 노드가 루트인 부분트리에서 i번재 노드가 검은색이 되는 횟수.
// up[i]: i번째 노드의 자식들이 없는 부분트리에서 i번째 노드가 검은색이 되는 횟수.
// 2. 전이: dp[i] = (dp[a1]+1)*(dp[a2]+1)*...*(dp[ak]+1) a는 노드 i의 자식
// up[i] = 1 + up[p]*(dp[a1]+1)*...(dp[ak]+1) (p는 노드i의 부모노드) (a는 i를 제외한 p의 자식노드)
// 3. 초기값/답: 리프노드의 dp = 1, 루트의 up = 1 /답: 각 노드의 dp*up