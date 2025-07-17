#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int sortWeight(pair<int,int> p1, pair<int,int> p2)
{
    return p1.first<p2.first;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> jewel;
    vector<int> bag;
    
    for(int i=0;i<n;i++)
    {
        int m,v;
        cin>>m>>v;
        jewel.push_back({m,v});
    }
    for(int i=0;i<k;i++)
    {
        int c;
        cin>>c;
        bag.push_back(c);
    }
    sort(bag.begin(), bag.end());
    sort(jewel.begin(), jewel.end(), sortWeight);
    priority_queue<int> pq;
    long long result=0;
    int jewelI=0;
    for(int i=0;i<k;i++)
    {
        int bagW=bag[i];
        
        while(jewelI<n && jewel[jewelI].first<=bagW)
        {
            pq.push(jewel[jewelI].second);
            jewelI++;
        }
        if(!pq.empty())
        {
            result+=pq.top();
            pq.pop();
        }
    }

    cout<<result;
}