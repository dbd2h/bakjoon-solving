#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

#define LEN (ll)(2e5+1)

using namespace std;

vector<int> graph[LEN];
ll res=0;

int dfs(int cur)
{
    res++;
    int max1=0;
    int max2=0;
    for(auto &next : graph[cur])
    {
        int num=dfs(next);
        if(max1<num)
        {
            max2=max1;
            max1=num;
        }
        else if(max2<num) max2=num;
    }
    res+=max2;
    return max1+1;
}

void program()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) graph[i].clear();
    res=0;
    for(int i=2;i<=n;i++)
    {
        int num;
        cin>>num;
        graph[num].push_back(i);
    }
    dfs(1);
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
        program();
    }
}