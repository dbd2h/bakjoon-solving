#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define LEN 1000001

using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    long long sumArr[LEN]={0};
    sumArr[0]=0;
    long long sumV=0;
    for(int i=1;i<=n;i++)
    {
        long long num;
        cin>>num;
        sumV+=num;
        sumArr[i]=sumV;
    }
    int mNum=0;
    vector<pair<pair<int,int>,long long>> v;
    for(int i=0;i<m+k;i++)
    {
        int isInput;
        cin>>isInput;
        if(isInput==1)
        {
            int a,b;
            long long c;
            cin>>a>>b>>c;
            v.push_back({{a,b},c});
            mNum++;
            if(mNum%1000==0)
            {
                int start=mNum/1000-1;
                start*=1000;
                priority_queue<pair<long long,long long>> pq1;
                priority_queue<pair<long long,long long>> pq2;
                for(int j=start;j<mNum;j++)
                {
                    pq1.push({-v[j].first.first,v[j].second});
                    pq2.push({-v[j].first.second,v[j].second});
                }
                long long curSum=0;
                long long curArr[LEN];
                curArr[0]=0;
                for(int j=1;j<=n;j++)
                {
                    while(!pq1.empty() && -pq1.top().first==j)
                    {
                        curSum+=pq1.top().second;
                        pq1.pop();

                    }
                    while(!pq2.empty() && -pq2.top().first+1==j)
                    {
                        curSum-=pq2.top().second;
                        pq2.pop();
                    }
                    curArr[j]=curSum;
                }
                curSum=0;
                for(int j=1;j<=n;j++)
                {
                    curSum+=curArr[j];
                    sumArr[j]+=curSum;
                }
            }
        }
        else if(isInput==2)
        {
            int a,b;
            cin>>a>>b;
            long long res=0;
            res=sumArr[b]-sumArr[a-1];
            int start=mNum/1000;
            start*=1000;
            for(int j=start;j<mNum;j++)
            {
                int l=v[j].first.first;
                int r=v[j].first.second;
                long long c=v[j].second;
                if(b<l || r<a) continue;
                res+=((long long)(min(r,b)-max(l,a)+1))*c;
            }
            cout<<res<<"\n";
        }
    }
}