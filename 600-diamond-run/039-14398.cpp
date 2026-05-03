#include <iostream>
#include <vector>
#include <queue>

#define LEN 201

#define INF 1e9
typedef long long ll;

using namespace std;

vector<int> graph[LEN];
int lmatch[LEN]={0};
int rmatch[LEN]={0};
int dist[LEN];

bool bfs(int n)
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(lmatch[i]==0)
        {
            q.push(i);
            dist[i]=0;
        }
        else dist[i]=INF;
    }
    bool found=false;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(auto& r : graph[cur])
        {
            int l=rmatch[r];
            if(l==0) found=true;
            else if(dist[l]==INF)
            {
                q.push(l);
                dist[l]=dist[cur]+1;
            }
        }
    }
    return found;
}

bool dfs(int cur)
{
    for(auto& r : graph[cur])
    {
        int l=rmatch[r];
        if(l==0 || (dist[l]==dist[cur]+1 && dfs(l)))
        {
            lmatch[cur]=r;
            rmatch[r]=cur;
            return true;
        }
    }
    return false;
}

bool binarySearch(ll l, ll r, ll num)
{
    if(l>r) return false;
    ll middle=(l+r)/2;
    if(middle*middle==num) return true;
    else if(middle*middle>num) return binarySearch(l,middle-1,num);
    else return binarySearch(middle+1,r,num);
}

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    int n;
    cin>>n;
    int odd=0;
    int even=0;
    ll oddArr[LEN];
    ll evenArr[LEN];
    for(int i=0;i<n;i++)
    {
        ll num;
        cin>>num;
        if(num%2==1)
        {
            odd++;
            oddArr[odd]=num;
        }
        else
        {
            even++;
            evenArr[even]=num;
        }
    }
    for(int i=1;i<=odd;i++)
    {
        for(int j=1;j<=even;j++)
        {
            ll a=oddArr[i];
            ll b=evenArr[j];
            if(gcd(a,b)!=1) continue;
            a=a*a;
            b=b*b;
            if(binarySearch(1,2000000,a+b)) graph[i].push_back(j);
        }
    }
    int res=0;
    while(bfs(odd))
    {
        for(int i=1;i<=odd;i++)
        {
            if(lmatch[i]==0 && dfs(i)) res++;
        }
    }
    cout<<res;
}