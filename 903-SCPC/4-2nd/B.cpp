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
#define LEN 10001
#define INF (1e9+1000000)

using namespace std;

int dp[2][LEN];
vector<pair<int,int>> v;

void program()
{
    v.clear();
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back({b,c});
        dp[0][i]=dp[1][i]=INF;
    }
    sort(v.begin(),v.end());
    dp[0][0]=v[0].first;
    for(int i=1;i<n;i++)
    {
        int y=v[i].first;
        int h=v[i].second;
        for(int j=0;j<=i;j++)
        {
            if(j==i)
            {
                dp[1][j]=min(dp[1][j],y);
                continue;
            }
            if(dp[0][j]==INF) continue;
            if(dp[0][j]>y)
            {
                dp[1][j+1]=min(dp[1][j+1],dp[0][j]+h);
                continue;   
            }
            int y2=dp[0][j]+h;
            if(y2<y)
            {
                dp[1][j+1]=min(dp[1][j+1],y2);
                dp[1][j]=min(dp[1][j],y);
            }
            else dp[1][j]=min(dp[1][j],y2);
            
        }
        for(int j=0;j<=i;j++)
        {
            dp[0][j]=dp[1][j];
            dp[1][j]=INF;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(dp[0][i]==INF) continue;
        cout<<i<<endl;
        break;
    }
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