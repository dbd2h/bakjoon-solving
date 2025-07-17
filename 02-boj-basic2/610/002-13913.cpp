#include <iostream>
#include <queue>
#include <stack>

#define MAX_LEN 100'001

using namespace std;

int main()
{
    int subinCount[MAX_LEN]={0};
    int parent[MAX_LEN]={0};
    queue<int> q;
    int subin, sister;
    cin>>subin>>sister;
    q.push(subin);
    int cur;
    for(int i=0;i<MAX_LEN;i++)
    {
        parent[i]=-1;
        subinCount[i]=-1;
    }
    subinCount[subin]=0;
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        if(cur==sister)
        {
            break;
        }
        if(cur-1>=0 && subinCount[cur-1]==-1)
        {
            subinCount[cur-1]=subinCount[cur]+1;
            parent[cur-1]=cur;
            q.push(cur-1);
        }
        if(cur+1<=MAX_LEN && subinCount[cur+1]==-1)
        {
            subinCount[cur+1]=subinCount[cur]+1;
            parent[cur+1]=cur;
            q.push(cur+1);
        }
        if(cur*2<=MAX_LEN && subinCount[cur*2]==-1)
        {
            subinCount[cur*2]=subinCount[cur]+1;
            parent[cur*2]=cur;
            q.push(cur*2);
        }
    }
    int p=parent[sister];
    stack<int> s;
    s.push(sister);
    while(p!=-1)
    {
        s.push(p);
        p=parent[p];
    }
    std::cout<<subinCount[sister]<<"\n";
    while(!s.empty())
    {
        std::cout<<s.top()<<" ";
        s.pop();
    }
}