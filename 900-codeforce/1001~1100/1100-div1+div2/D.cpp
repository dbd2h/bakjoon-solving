#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
typedef long long ll;
typedef long double lld;

#define LEN 100001

using namespace std;

void program()
{
    int n;
    cin>>n;
    int arr[LEN][2];
    int arrLen[LEN];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i][0];
        arrLen[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        if(arr[i][0]>a)
        {
            int c=arr[i][0];
            arr[i][0]=a;
            a=c;
        }
        arr[i][1]=a;
    }
    int parent[LEN];
    for(int i=1;i<=n;i++) parent[i]=i;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=1;i<=n;i++)
    {
        pq.push({arr[i][0],i});
    }
    int len=n;
    while(!pq.empty() && len>1)
    {
        int cur=pq.top().first;
        int idx=pq.top().second;
        pq.pop();
        if(parent[idx]!=idx || arr[idx][0]!=cur) continue;
        int curLen=arrLen[idx];
        int nextI=idx+curLen;
        int a=0;
        if(idx!=1)
        {
            a=idx-1;
            while(parent[a]!=a)
            {
                int ap=parent[a];
                parent[a]=parent[ap];
                a=ap;
            }
        }
        if(a!=0)
        {
            if(nextI>n || arr[nextI][0]>arr[a][0]) nextI=a;
        }   
        int curArr[4];
        curArr[0]=arr[nextI][0];
        curArr[1]=arr[nextI][1];
        curArr[2]=arr[idx][0];
        curArr[3]=arr[idx][1];
        sort(curArr,curArr+4);
        if(nextI<idx)
        {
            int c=nextI;
            nextI=idx;
            idx=c;
        }
        parent[nextI]=idx;
        arr[idx][0]=curArr[1];
        arr[idx][1]=curArr[2];
        arrLen[idx]+=arrLen[nextI];
        pq.push({arr[idx][0],idx});
        len--;
    }
    cout<<arr[1][0]<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}