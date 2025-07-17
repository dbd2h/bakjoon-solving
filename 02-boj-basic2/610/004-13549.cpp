#include <iostream>
#include <deque>

#define MAX_LEN 100'001

using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    int count[MAX_LEN]={0};
    for(int i=0;i<MAX_LEN;i++)
    {
        count[i]=-1;
    }
    count[n]=0;
    deque<int> dq;
    dq.push_back(n);
    int cur=n;
    while(!dq.empty())
    {
        cur=dq.front();
        dq.pop_front();
        if(cur==k)
        {
            break;
        }
        if(cur-1>=0 && count[cur-1]==-1)
        {
            dq.push_back(cur-1);
            count[cur-1]=count[cur]+1;
        }
        if(cur+1<MAX_LEN && count[cur+1]==-1)
        {
            dq.push_back(cur+1);
            count[cur+1]=count[cur]+1;
        }
        if(cur*2<MAX_LEN && count[cur*2]==-1)
        {
            dq.push_front(cur*2);
            count[cur*2]=count[cur];
        }
    }
    cout<<count[k];
}