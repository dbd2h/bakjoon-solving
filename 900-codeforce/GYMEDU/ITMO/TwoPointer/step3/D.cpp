#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
typedef long long ll;
typedef long double lld;

using namespace std;

int main()
{
    vector<int> v[4];
    for(int i=0;i<4;i++)
    {
        int n;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            int num;
            cin>>num;
            v[i].push_back(num);
        }
        sort(v[i].begin(),v[i].end());
    }
    int idxArr[4]={0};
    int res=100000;
    int resArr[4];
    while(true)
    {
        int inc=-1;
        int incV=-1;
        int maxV=0;
        int minV=100000;
        for(int i=0;i<4;i++)
        {
            int idx=idxArr[i];
            int cur=v[i][idx];
            maxV=max(maxV,cur);
            minV=min(minV,cur);
            if(v[i].size()==idx+1) continue;
            if(inc==-1 || incV>cur)
            {
                inc=i;
                incV=cur;
            }
        }
        if(res>maxV-minV)
        {
            for(int i=0;i<4;i++) resArr[i]=v[i][idxArr[i]];
            res=maxV-minV;
        }
        if(inc==-1) break;
        idxArr[inc]++;
    }
    for(int i=0;i<4;i++) cout<<resArr[i]<<" ";
}