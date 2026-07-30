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
#define LEN 200001

using namespace std;

int arr[LEN];
ll dp[LEN][3];
vector<int> zeroV;
vector<pair<int,int>> twoV;

void program()
{
    int n;
    cin>>n;
    int sumV=0;
    zeroV.clear();
    twoV.clear();
    zeroV.push_back(0);
    twoV.push_back({0,0});
    int maxNum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        sumV+=arr[i];
        dp[i][0]=dp[i][1]=dp[i][2]=-1;
        if(arr[i]==0) zeroV.push_back(i);
        else if(arr[i]>=2)
        {
            int num=arr[i];
            maxNum=max(maxNum,num);
            while(num>=2)
            {
                twoV.push_back({num,i});
                num--;
            }
        }
    }
    if(sumV-n==2 && zeroV.size()==1 && maxNum==3)
    {
        cout<<1<<"\n";
        return;
    }
    dp[0][0]=dp[0][1]=dp[0][2]=0;
    int bef=0;
    int l=0;
    int len=zeroV.size()-1;
    for(int i=1;i<=len;i++)
    {
        int zeroI=zeroV[i];
        int dist=abs(zeroI-twoV[i].second);
        dp[i][0]=dp[i-1][0]+dist;
        if(sumV-n<=0) continue;
        dist=abs(zeroI-twoV[i+1].second);
        if(dp[i-1][1]!=-1) dp[i][1]=dp[i-1][1]+dist;
        if(twoV[i+1].second!=twoV[i].second)
        {
            if(dp[i][1]==-1) dp[i][1]=dp[i-1][0]+dist;
            else dp[i][1]=min(dp[i][1],dp[i-1][0]+dist);
        }
        if(sumV-n<=1) continue;
        dist=abs(zeroI-twoV[i+2].second);
        if(dp[i-1][2]!=-1) dp[i][2]=dp[i-1][2]+dist;
        if(twoV[i+2].second!=twoV[i+1].second && dp[i-1][1]!=-1)
        {
            if(dp[i][2]==-1) dp[i][2]=dp[i-1][1]+dist;
            else dp[i][2]=min(dp[i][2],dp[i-1][1]+dist);
        } 
        if(twoV[i+2].second!=twoV[i+1].second)
        {
            if(twoV[i].first==3)
            {
                if(dp[i][2]==-1) dp[i][2]=dp[i-1][0]+dist+1;
                else dp[i][2]=min(dp[i][2],dp[i-1][0]+dist+1);
            }
            else
            {
                if(dp[i][2]==-1) dp[i][2]=dp[i-1][0]+dist;
                else dp[i][2]=min(dp[i][2],dp[i-1][0]+dist);
            }
        }
    }
    if(sumV-n==2 && twoV[len-1].first==3 && zeroV[len]<twoV[len-1].second) dp[len][0]++;
    ll res=dp[len][0];
    if(sumV-n>=1 && dp[len][1]!=-1) res=min(res,dp[len][1]);
    if(sumV-n>=2 && dp[len][2]!=-1) res=min(res,dp[len][2]);
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