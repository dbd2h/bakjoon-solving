#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        q.push(i);
    }
    int idx=0;
    cout<<"<";
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        idx++;
        if(idx%k==0)
        {
            idx%=k;
            cout<<cur;
            if(q.empty())
            {
                break;
            }
            else
            {
                cout<<", ";
            }
            continue;
        }
        q.push(cur);
    }
    cout<<">";
}