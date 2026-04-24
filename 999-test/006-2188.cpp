#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<int>(& graphV)[1001], int workArr[1001], bool check[1001], int cur, int befW)
{
    for(auto& next : graphV[cur])
    {
        if(next==befW) continue;
        if(check[next]) continue;
        if(workArr[next]!=-1)
        {
            check[next]=1;
            if(dfs(graphV,workArr,check,workArr[next],next))
            {
                workArr[next]=cur;
                check[next]=0;
                return true;
            }
        }
        else
        {
            workArr[next]=cur;
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    int empArr[1001];
    int workArr[1001];
    vector<int> graphV[1001];
    for(int i=1;i<=n;i++)
    {
        int count;
        cin>>count;
        empArr[i]=-1;
        for(int j=0;j<count;j++)
        {
            int num;
            cin>>num;
            graphV[i].push_back(num);
        }
    }
    for(int i=1;i<=m;i++)
    {
        workArr[i]=-1;
    }
    for(int i=1;i<=n;i++)
    {
        bool check[1001]={0};
        dfs(graphV,workArr,check,i,-1);
    }
    int res=0;
    for(int i=1;i<=m;i++)
    {
        if(workArr[i]==-1) continue;
        res++;
    }
    cout<<res;
}