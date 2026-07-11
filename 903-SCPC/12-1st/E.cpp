#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 2001
#define INF (lld)(1e18)

using namespace std;

bool isSame(lld n1, lld n2)
{   
    lld diff=abs(n1-n2);
    if(diff<=(1.0e-16)) return true;
    else return false;
}

int cmp(pair<pair<lld,lld>,lld> p1, pair<pair<lld,lld>,lld> p2)
{
    lld slp1=-p1.first.first/p1.first.second;
    lld slp2=-p2.first.first/p2.first.second;
    if(isSame(slp1,slp2)) return -p1.second/p1.first.second<-p2.second/p2.first.second;
    return slp1<slp2;
}

lld x[LEN][LEN];

void program()
{
    vector<pair<pair<lld,lld>,lld>> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        lld a,b,c;
        cin>>a>>b>>c;
        v.push_back({{a,b},c});
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            pair<pair<lld,lld>,lld> p1,p2;
            p1=v[i];
            p2=v[j];
            lld slp1=-p1.first.first/p1.first.second;
            lld slp2=-p2.first.first/p2.first.second;
            if(isSame(slp1,slp2))
            {
                x[i][j]=INF;
                continue;
            } 
            lld boonja=(p2.second/p2.first.second-p1.second/p1.first.second);
            lld boonmo=(p1.first.first/p1.first.second-p2.first.first/p2.first.second);
            x[i+1][j+1]=boonja/boonmo;
        }
    }
    int dp[LEN];
    for(int i=0;i<=n;i++) dp[i]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=i-1;j>=1;j--)
        {
            pair<pair<lld,lld>,lld> p1,p2;
            p1=v[i-1];
            p2=v[j-1];
            lld slp1=-p1.first.first/p1.first.second;
            lld slp2=-p2.first.first/p2.first.second;
            if(isSame(slp1,slp2)) continue;
            
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<endl;
        program();
    }
}