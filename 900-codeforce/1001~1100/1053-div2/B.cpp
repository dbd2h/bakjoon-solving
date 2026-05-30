#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

void program()
{
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    priority_queue<int, vector<int>, greater<int>> pq;
    int cur=1;
    vector<int> res;
    for(int i=0;i<m;i++)
    {
        int num;
        cin>>num;
        pq.push(num);
    }
    for(int i=0;i<n;i++)
    {
        int isB=s[i]-'A';
        if(isB)
        {
            cur++;
            while(!pq.empty() && pq.top()<=cur)
            {
                if(res.size()==0 || res[res.size()-1]!=pq.top()) res.push_back(pq.top());
                if(pq.top()==cur) cur++;
                pq.pop();
            }
            pq.push(cur);
            while(!pq.empty() && pq.top()<=cur)
            {
                if(res.size()==0 || res[res.size()-1]!=pq.top()) res.push_back(pq.top());
                if(pq.top()==cur) cur++;
                pq.pop();
            }
        }
        else
        {
            cur++;
            pq.push(cur);
        }
    }
    while(!pq.empty())
    {
        if(res.size()==0 || res[res.size()-1]!=pq.top()) res.push_back(pq.top());
        pq.pop();
    }
    cout<<res.size()<<"\n";
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<"\n";
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