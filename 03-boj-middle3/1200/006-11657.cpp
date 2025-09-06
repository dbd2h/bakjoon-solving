#include <iostream>
#include <vector>
typedef long long ll;

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<pair<int,int>,int>> edgeV;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edgeV.push_back({{a,b},c});
    }
    bool check[501]={0};
    ll weight[501]={0};
    check[1]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            pair<pair<int,int>,int> p=edgeV[j];
            int a,b,c;
            a=p.first.first;
            b=p.first.second;
            c=p.second;
            if(!check[a]) continue;
            
            if(!check[b] || (weight[a]+c<weight[b]))
            {
                weight[b]=weight[a]+ (ll)c;
                check[b]=true;
            } 
            else continue;
            if(i==n-1)
            {
                cout<<-1;
                return 0;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(!check[i])
        {
            cout<<-1<<"\n";
            continue;
        }
        cout<<weight[i]<<"\n";
    }
}