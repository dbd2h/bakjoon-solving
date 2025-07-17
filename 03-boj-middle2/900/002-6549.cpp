#include <iostream>
#include <queue>

using namespace std;

void histogram(int n)
{
    int arr[100000]={0};
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        pq.push({arr[i],i});
    }
    long long res=0;
    int check[100000]={0};
    while(!pq.empty())
    {
        int i,h;
        h=pq.top().first;
        i=pq.top().second;
        pq.pop();
        int lv,rv;
        lv=0;
        rv=0;
        int li,ri;
        li=i;
        ri=i;
        if(i!=0)
        {
            lv=check[i-1];
        }
        if(i!=n-1)
        {
            rv=check[i+1];
        }
        li=i-lv;
        ri=i+rv;
        long long tot=lv+rv+1;
        check[li]=tot;
        check[ri]=tot;
        long long s=tot*h;
        if(res<s) res=s;
    }
    cout<<res<<"\n";
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    while(n!=0)
    {
        histogram(n);
        cin>>n;
    }
}