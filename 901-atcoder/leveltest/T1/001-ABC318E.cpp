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
#define LEN 300001

using namespace std;

vector<int> v[LEN];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int num;
        cin>>num;
        v[num].push_back(i);
    }
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        if(v[i].size()<=1) continue;
        int len=v[i].size();
        for(int j=0;j<len-1;j++)
        {
            ll num=v[i][j+1]-v[i][j]-1;
            int right=len-(j+1);
            int left=j+1;
            res+=num*right*left;
        }
    }
    cout<<res;
}