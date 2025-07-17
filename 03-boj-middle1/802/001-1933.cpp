#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool compare(pair<int,pair<int,int>> p1, pair<int,pair<int,int>> p2)
{
    if(p1.first==p2.first) return p1.second.first > p2.second.first;
    return p1.first < p2.first;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,pair<int,int>>> v; // l,{높이,r}
    for(int i=0;i<n;i++)
    {
        int l,h,r;
        cin>>l>>h>>r;
        v.push_back({l,{h,r}});
    }
    sort(v.begin(), v.end(), compare);
    priority_queue<pair<int,int>> pq;
    int curH=0;
    int curX=0;
    for(int i=0;i<n+1;i++)
    {
        int x;
        pair<int,int> p;
        if(i<n)
        {
            x=v[i].first;
            p=v[i].second;
        }
        else
        {
            x=1000000001;
        }
        while(!pq.empty() && pq.top().second<x)
        {
            if(pq.top().second>curX) curX=pq.top().second;
            pq.pop();
            if(pq.empty())
            {
                curH=0;
            }
            else if(pq.top().second<=curX)
            {
                continue;
            }
            else if(pq.top().first==curH)
            {
                continue;
            }
            else
            {
                curH=pq.top().first;
            }
            cout<<curX<<" "<<curH<<" ";
        }
        if(i==n) break;
        curX=x;
        if(pq.empty())
        {
            pq.push(p);
            curH=pq.top().first;
        }
        else if(pq.top().second==x)
        {
            pq.pop();
            pq.push(p);
            if(curH==pq.top().first)
            {
                continue;
            }
            curH=pq.top().first;
        }
        else
        {
            pq.push(p);
            if(curH==pq.top().first)
            {
                continue;
            }
            curH=pq.top().first;
        }
        cout<<curX<<" "<<curH<<" ";
    }
    
}



/*
안에 아무것도 없을 때: 출력하고 넣고,
넣기 전 -> top값의 r값이 넣는 값보다 작으면 처리 -> 이후에 현재 x값 이전 top의 r값으로 바꿔주고 그거보다 r값 작으면 처리, 작지 않다면 curH 바꿔주고 출력 이거 반복
이후에 넣고 

1 11 3 13 9 0 12 7 16 3 19 18 22 3 23 13 29 0








*/