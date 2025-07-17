#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> c[101];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        c[a].push_back(b);
        c[b].push_back(a);
    }
    queue<int> q;
    int check[101]={0};
    check[1]=1;
    q.push(1);
    int result=0;
    while(!q.empty())
    {
        int n=q.front();
        q.pop();
        for(int i=0;i<c[n].size();i++)
        {
            int n1=c[n][i];
            if(check[n1]) continue;
            q.push(n1);
            check[n1]=1;
            result++;
        }
    }
    cout<<result;
}