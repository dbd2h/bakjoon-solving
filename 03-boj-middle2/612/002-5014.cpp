#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main()
{
    map<int,bool> m;
    int f,s,g,u,d;
    cin>>f>>s>>g>>u>>d;
    queue<pair<int,int>> q;
    q.push({s,0});
    m[s]=1;
    if(s==g)
    {
        cout<<0;
        return 0;
    }
    while(!q.empty())
    {
        int nowF=q.front().first;
        int c=q.front().second;
        q.pop();
        if(nowF+u==g)
        {
            cout<<c+1;
            return 0;
        }
        if(nowF-d==g)
        {
            cout<<c+1;
            return 0;
        }
        if(nowF+u<=f && !m[nowF+u])
        {
            q.push({nowF+u,c+1});
            m[nowF+u]=true;
        }
        if(nowF-d>=1 && !m[nowF-d])
        {
            q.push({nowF-d,c+1});
            m[nowF-d]=true;
        }
    }
    cout<<"use the stairs";
}