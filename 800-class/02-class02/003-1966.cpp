#include <iostream>
#include <queue>

using namespace std;

void problem()
{
    int n,m;
    cin>>n>>m;
    queue<pair<int,int>> q;
    int check[10]={0};
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        q.push({i,num});
        check[num]++;
    }
    int cur=9;
    while(check[cur]==0 && cur>0) cur--;
    int res=1;
    while(!q.empty())
    {
        int order=q.front().first;
        int ipt=q.front().second;
        q.pop();
        if(cur==ipt)
        {
            if(m==order)
            {
                cout<<res<<"\n";
                return;
            }
            check[ipt]--;
            while(check[cur]==0 && cur>0) cur--;
            res++;
            continue;
        }
        q.push({order,ipt});
    }
}

int main()
{   
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        problem();
    }
}