#include <iostream>
#include <queue>
#include <tuple>

#define MAX_LEN 1'050

using namespace std;

int main()
{
    int s;
    cin>>s;
    queue<tuple<int,int,int>> q;
    q.push({1,0,0});
    int cur=1;
    int clipboard=0;
    int count=0;
    while(!q.empty())
    {
        tuple<int,int,int> a;
        a=q.front();
        cur=get<0>(a);
        clipboard=get<1>(a);
        count=get<2>(a);
        if(cur==s)
        {
            break;
        }
        q.pop();
        if(cur+clipboard<=MAX_LEN && clipboard!=0)
        {
            q.push({cur+clipboard, clipboard, count+1});
        }
        if(cur!=clipboard)
        {
            q.push({cur,cur,count+1});
        }
        if(cur-1>count && clipboard!=0 && clipboard != cur)
        {
            q.push({cur-1, clipboard, count+1});
        }
    }
    cout<<count;
}