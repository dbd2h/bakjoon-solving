#include <iostream>
#include <queue>
#include <string>
#include <map>

using namespace std;

int main()
{
    priority_queue<string> pq;
    map<string, int> m;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string name,work;
        cin>>name>>work;
        if(work=="enter")
        {
            m[name]=1;
            pq.push(name);
        }
        else if(work=="leave")
        {
            m[name]=0;
        }
    }
    string bes="";
    while(!pq.empty())
    {
        string s=pq.top();
        pq.pop();
        if(s==bes) continue;
        bes=s;
        if(m[s]) cout<<s<<"\n";
    }
}