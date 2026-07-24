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
#define NLEN 10001
#define MLEN 301

using namespace std;

int arr1[NLEN];
int arr2[MLEN];

void program()
{
    int n,m,K;
    cin>>n>>m>>K;
    for(int i=0;i<n;i++) cin>>arr1[i];
    for(int i=0;i<m;i++) cin>>arr2[i];
    int res=0;
    for(int i=0;i<=n-m;i++)
    {
        vector<pair<int,int>> v;
        for(int j=0;j<m;j++)
        {
            v.push_back({arr2[j],arr1[j+i]});
        }
        sort(v.begin(),v.end());
        int resArr[MLEN];
        int len=0;
        for(int j=0;j<m;j++)
        {
            int cur=v[j].second;
            for(int k=len-1;k>=-1;k--)
            {
                if(k==-1 || resArr[k]<cur)
                {
                    resArr[k+1]=cur;
                    if(k+1==len) len++;
                    break;
                } 
            }
        }
        if(m-len<=K) res++;
    }
    cout<<res<<"\n";
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