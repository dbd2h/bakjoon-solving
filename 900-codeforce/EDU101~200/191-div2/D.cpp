#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 200001

using namespace std;

vector<int> blockV[LEN];
int cntArr[LEN];

bool check(vector<int> &v, int x, int y)
{
    int len=v.size();
    int cnt[LEN];
    for(int i=0;i<len;i++) cnt[i]=0;
    for(int i=0;i<len;)
    {
        int cur=v[i];
        while(i<len && cur==v[i]) i++;
        cnt[cur]++;
        if(cnt[cur]>1) return false;
    }
    return true;
}

void program()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }
    auto sortV=v;
    sort(sortV.begin(),sortV.end());
    sortV.erase(unique(sortV.begin(),sortV.end()),sortV.end());
    for(int i=0;i<n;i++)
    {
        v[i]=lower_bound(sortV.begin(),sortV.end(),v[i])-sortV.begin();
    }
    for(int i=0;i<n;i++)
    {
        blockV[i].clear();
        cntArr[i]=0;
    }
    for(int i=0;i<n;)
    {
        int cur=v[i];
        int j=i;
        while(i<n && cur==v[i]) i++;
        blockV[cur].push_back(i);
        blockV[cur].push_back(i-1);
        blockV[cur].push_back(j);
        blockV[cur].push_back(j-1);
        cntArr[cur]++;
    }
    bool isT=true;
    for(int i=0;i<n;i++)
    {
        if(cntArr[i]<=1) continue;
        if(cntArr[i]>=4)
        {
            isT=false;
            break;
        }
        sort(blockV[i].begin(),blockV[i].end());
        blockV[i].erase(unique(blockV[i].begin(),blockV[i].end()),blockV[i].end());
        bool isOk=false;
        for(auto &x : blockV[i])
        {
            for( auto &y : blockV[i])
            {
                if(x==y) continue;
                if(x<0 || x>=n || y<0 || y>=n) continue;
                swap(v[x],v[y]);
                isOk=check(v,x,y);
                swap(v[x],v[y]);
                if(isOk) break;
            }
            if(isOk) break;
        }
        if(isOk) break;
        isT=false;
        break;
    }
    if(isT) cout<<"YES\n";
    else cout<<"NO\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}
