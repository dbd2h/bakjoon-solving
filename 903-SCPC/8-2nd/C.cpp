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
#define LEN 100001

using namespace std;

vector<int> graph[LEN*3];
vector<int> rGraph[LEN*3];
int dp[LEN*3];
int dpCp[LEN*3];
vector<pair<int,int>> G[LEN];
vector<int> rG[LEN];
stack<int> st;
bool check[LEN*3];
int sccId[LEN*3];
int sccCount;

void dfsM1(int cur)
{
    check[cur]=1;
    for(auto&nextP : G[cur])
    {
        int next=nextP.first;
        if(check[next]) continue;
        dfsM1(next);
    }
    st.push(cur);
}

void dfsM2(int cur)
{
    sccId[cur]=sccCount;
    for(auto&next : rG[cur])
    {
        if(sccId[next]!=0) continue;
        dfsM2(next);
    }
}

bool dfsM3(int cur, int idx, bool check2[3])
{
    for(auto&nextP : G[cur])
    {
        int next=nextP.first;
        int alpha=nextP.second;
        if(dp[next*3-2]>=dp[cur*3-2] && dp[next*3-1]>=dp[cur*3-1] && dp[next*3]>=dp[cur*3] && dp[next*3+alpha-2]>=dp[cur*3-2+(alpha+3-1)%3]+1) continue;
        dp[next*3-2]=max(dp[next*3-2],dp[cur*3-2]);
        dp[next*3-1]=max(dp[next*3-1],dp[cur*3-1]);
        dp[next*3]=max(dp[next*3],dp[cur*3]);
        dp[next*3+alpha-2]=max(dp[next*3+alpha-2],dp[cur*3-2+(alpha+3-1)%3]+1);
        if(sccId[next]!=idx) continue;
        check2[alpha]=1;
        bool isF=true;
        for(int i=0;i<3;i++)
        {
            if(check2[i]) continue;
            isF=false;
            break;
        }
        if(isF) return false;
        if(!dfsM3(next,idx,check2)) return false;
    }
    return true;
}

void dfs1(int cur)
{
    check[cur]=1;
    for(auto&next : graph[cur])
    {
        if(check[next]) continue;
        dfs1(next);
    }
    st.push(cur);
}

void dfs2(int cur)
{
    sccId[cur]=sccCount;
    for(auto&next : rGraph[cur])
    {
        if(sccId[next]!=0) continue;
        dfs2(next);
    }
}

void program()
{
    int n,m,k;
    cin>>n>>m>>k;
    sccCount=0;
    st=stack<int>();
    for(int i=1;i<=n*3;i++)
    {
        graph[i].clear();
        rGraph[i].clear();
        sccId[i]=0;
        check[i]=0;
        dp[i]=0;
        dpCp[i]=0;
    } 
    for(int i=1;i<=n;i++)
    {
        G[i].clear();
        rG[i].clear();
    }
    for(int i=0;i<m;i++)
    {
        int a,b;
        char c;
        cin>>a>>b>>c;
        if(k==-1)
        {
            G[a].push_back({b,c-'A'});
            rG[b].push_back(a);
            continue;
        }
        if(c=='B')
        {
            graph[a*3-2].push_back(b*3-1);
            rGraph[b*3-1].push_back(a*3-2);
        } 
        if(c=='C')
        {
            graph[a*3-1].push_back(b*3);
            rGraph[b*3].push_back(a*3-1);
        } 
        if(c=='A')
        {
            graph[a*3].push_back(b*3-2);
            rGraph[b*3-2].push_back(a*3);
        } 
        
    }
    if(k==-1)
    {
        for(int i=1;i<=n;i++)
        {
            if(check[i]) continue;
            dfsM1(i);
        }
        vector<int> v;
        while(!st.empty())
        {
            int cur=st.top();
            v.push_back(cur);
            st.pop();
            if(sccId[cur]!=0) continue;
            sccCount++;
            dfsM2(cur);
        }
        
        for(auto&cur : v)
        {
            bool check2[3]={0};
            if(!dfsM3(cur,sccId[cur],check2))
            {
                cout<<-1<<"\n";
                return;
            }
        }
        int res=0;
        for(int i=1;i<=n*3;i++)
        {
            res=max(res,dp[i]);
        }
        cout<<res<<"\n";
        return;
    }
    for(int i=1;i<=n*3;i++)
    {
        if(check[i]) continue;
        dfs1(i);
    }
    vector<int> v;
    while(!st.empty())
    {
        int cur=st.top();
        st.pop();
        if(sccId[cur]!=0)
        {
            cout<<-1<<"\n";
            return;
        }
        sccCount++;
        v.push_back(cur);
        dfs2(cur);
    }
    for(auto&cur : v)
    {
        for(auto&next : graph[cur])
        {
            dp[next]=max(dp[next],dp[cur]+1);
        }
    }
    while(k--)
    {
        for(int i=1;i<=n*3;i++) dpCp[i]=dp[i];
        for(auto&cur : v)
        {
            int curA=cur-(cur+2)%3;
            for(int i=0;i<3;i++)
            {
                int cur2=curA+i;
                for(auto&next : graph[cur2])
                {
                    int nextA=next-(next+2)%3;
                    if(graph[nextA+(cur-1)%3].size()==0) continue;
                    dpCp[nextA+(cur-1)%3]=max(dpCp[nextA+(cur-1)%3],dp[cur]);
                }
            }
        }
        for(auto&cur : v)
        {
            for(auto&next : graph[cur])
            {
                dpCp[next]=max(dpCp[next],dpCp[cur]+1);
            }
        }
        for(int i=1;i<=n*3;i++)
        {
            dp[i]=dpCp[i];
        } 
    }
    int res=0;
    for(int i=1;i<=n*3;i++)
    {
        res=max(res,dp[i]);
    }
    cout<<res<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<endl;
        program();
    }
}