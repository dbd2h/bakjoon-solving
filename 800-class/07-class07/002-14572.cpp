#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cmp(pair<int,int> p1, pair<int,int> p2)
{
    return p1.second<p2.second;
}

int main()
{
    vector<pair<int,int>> v;
    bool algorithmArr[100001][31]={0};
    int n,k,d;
    cin>>n>>k>>d;
    for(int i=1;i<=n;i++)
    {
        int m,b;
        cin>>m>>b;
        v.push_back({i,b});
        for(int j=0;j<m;j++)
        {
            int alg;
            cin>>alg;
            algorithmArr[i][alg]=1;
        }
    }
    sort(v.begin(), v.end(), cmp);
    int algKnow[31]={0};
    int lastI=0;
    int res=0;
    for(int i=0;i<n;i++)
    {
        int curD=v[i].second;
        int cur=v[i].first;
        while(lastI!=n && v[lastI].second-curD<=d)
        {
            for(int j=1;j<=k;j++)
            {
                if(algorithmArr[v[lastI].first][j])
                {
                    algKnow[j]++;
                }
            }
            lastI++;
        }
        int knowC=0;
        int everyKnowC=0;
        int c=lastI-i;
        for(int j=1;j<=k;j++)
        {
            if(algKnow[j]>0)
            {
                knowC++;
                if(algKnow[j]==c) everyKnowC++;
            }
        }
        int curRes=(knowC-everyKnowC)*c;
        if(res<curRes)res=curRes;
        for(int j=1;j<=k;j++)
        {
            if(algorithmArr[cur][j]) algKnow[j]--;
        }


        if(lastI==n) break;
    }
    cout<<res;
}