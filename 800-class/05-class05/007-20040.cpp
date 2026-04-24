#include <iostream>
#include <vector>
#define LEN 500000

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int parent[LEN];
    vector<pair<int,int>> inputV;
    for(int i=0;i<n;i++) parent[i]=-1;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        inputV.push_back({a,b});
    }
    for(int i=1;i<=m;i++)
    {
        int a=inputV[i-1].first;
        int b=inputV[i-1].second;
        int ap=a;
        int bp=b;
        while(parent[ap]!=-1) ap=parent[ap];
        while(parent[bp]!=-1) bp=parent[bp];
        if(ap==bp)
        {
            cout<<i;
            return 0;
        }
        if(ap>bp)
        {
            int c=b;
            b=a;
            a=c;
            ap=bp;
        }
        bp=parent[b];
        while(bp!=-1)
        {
            parent[b]=ap;
            b=bp;
            bp=parent[b];
        }
        parent[b]=ap;
    }
    cout<<0;
}