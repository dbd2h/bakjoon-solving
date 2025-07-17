#include <iostream>
#include <queue>

#define MAX_LEN 100'001

using namespace std;

int main()
{
    int subinCount[MAX_LEN]={0};
    queue<int> q;
    int subin, sister;
    cin>>subin>>sister;
    q.push(subin);
    int cur;
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        if(cur==sister)
        {
            break;
        }
        if(cur-1>=0 && subinCount[cur-1]==0)
        {
            subinCount[cur-1]=subinCount[cur]+1;
            q.push(cur-1);
        }
        if(cur+1<=MAX_LEN && subinCount[cur+1]==0)
        {
            subinCount[cur+1]=subinCount[cur]+1;
            q.push(cur+1);
        }
        if(cur*2<=MAX_LEN && subinCount[cur*2]==0)
        {
            subinCount[cur*2]=subinCount[cur]+1;
            q.push(cur*2);
        }
    }
    cout<<subinCount[sister];
}