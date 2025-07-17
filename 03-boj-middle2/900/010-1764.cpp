#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    map<string,int> sm;
    priority_queue<string, vector<string>, greater<string>> pq;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        pq.push(s);
        sm[s]=1;
    }
    for(int i=0;i<m;i++)
    {
        string s;
        cin>>s;
        sm[s]++;
    }
    int c=0;
    vector<string> v;
    while(!pq.empty())
    {
        string s=pq.top();
        pq.pop();
        if(sm[s]==2)
        {
            v.push_back(s);
            c++;
        }
    }
    cout<<c<<"\n";
    for(int i=0;i<c;i++)
    {
        cout<<v[i]<<"\n";
    }
}