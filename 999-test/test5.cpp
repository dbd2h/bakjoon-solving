#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[50000]={0};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int numC=0;
    int curr=0;
    vector<pair<int,int>> groupV;
    for(int i=0;i<n;i++)
    {
        int count=1;
        curr=arr[i];
        while(i+1<n && curr==arr[i+1])
        {
            i++;
            count++;
        }
        numC++;
        groupV.push_back({curr,count});
    }
    int sumV=0;
    int finI=0;
    priority_queue<pair<int,int>> pq;
    vector<int> disV;
    for(int i=0;i<numC;i++)
    {
        int num,c;
        num=groupV[i].first;
        c=groupV[i].second;
        while(finI<numC && num+k>=groupV[finI].first)
        {
            sumV+=groupV[finI].second;
            finI++;
        }
        pq.push({sumV, num});
        disV.push_back(sumV);
        sumV-=c;
    }
    if(pq.top().first==n)
    {
        cout<<n;
        return 0;
    }
    int maxV=0;
    for(int i=0;i<numC;i++)
    {
        int curr=groupV[i].first;
        int group1=disV[i];
        while(!pq.empty() && curr+k>=pq.top().second) pq.pop();
        if(pq.empty())
        {
            break;
        }
        if(group1+pq.top().first>maxV)
        {
            maxV=group1+pq.top().first;
        }
    }
    cout<<maxV;
}

// 1부터 k 차이 나는 개수, 2부터.. ,3부터.. , ..., 마지막꺼 포함하는 거
// pq에 pair{개수, 시작점} 넣기