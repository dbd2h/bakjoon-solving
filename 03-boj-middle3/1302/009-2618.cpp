#include <iostream>
#include <vector>
#include <stack>

#define LEN 1003

using namespace std;

int absF(int a)
{
    if(a<0) a=-a;
    return a;
}

int main()
{
    vector<pair<int,int>> v;
    vector<int> carV[LEN];
    int n,w;
    cin>>n>>w;
    v.push_back({1,1});
    v.push_back({n,n});
    for(int i=0;i<w;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    int AtoB[LEN][LEN];
    for(int i=0;i<w+2;i++)
    {
        for(int j=i+1;j<w+2;j++)
        {   
            int a1=v[i].first;
            int b1=v[i].second;
            int a2=v[j].first;
            int b2=v[j].second;
            int dis=absF(a1-a2);
            dis+=absF(b1-b2);
            AtoB[i][j]=dis;
        }
    }
    int dp[LEN][LEN];
    dp[0][0]=AtoB[1][2];
    dp[0][1]=AtoB[0][2];
    carV[0].push_back(1);
    carV[1].push_back(0);
    for(int i=0;i<w-1;i++)
    {
        int idx=0;
        for(int j=0;j<i+2;j++)
        {
            int cur=dp[i][j];
            dp[i+1][j]=cur+AtoB[i+2][i+3];
            int bef=carV[j][carV[j].size()-1];
            carV[j].push_back(bef);
            if(j==0)
            {
                dp[i+1][i+2]=cur+AtoB[j][i+3];
                continue;
            }
            if(dp[i+1][i+2]>cur+AtoB[j][i+3])
            {
                dp[i+1][i+2]=cur+AtoB[j][i+3];
                idx=j;
            } 
        }
        for(int j=0;j<carV[idx].size()-1;j++)
        {
            carV[i+2].push_back(carV[idx][j]);
        }
        carV[i+2].push_back((carV[idx][carV[idx].size()-1]+1)%2);
    }
    
    int res=1e9;
    int idx=-1;
    for(int i=0;i<w+1;i++)
    {   
        if(res>dp[w-1][i])
        {
            res=dp[w-1][i];
            idx=i;
        }
    }
    cout<<res<<"\n";
    int len=carV[idx].size();
    for(int i=0;i<len;i++)
    {
        cout<<carV[idx][i]+1<<"\n";
    }
}