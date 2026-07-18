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
#define LEN 100001

using namespace std;

int main()
{
    int alpha[26]={0};
    int n,m;
    cin>>n>>m;
    int arr[LEN];
    string s1,s2;
    cin>>s1>>s2;
    for(int i=1;i<=n;i++)
    {
        int cur=s1[i-1]-'a';
        arr[i]=cur;
    }
    for(int i=0;i<m;i++)
    {
        int cur=s2[i]-'a';
        alpha[cur]++;
    }
    int l=0;
    int r=0;
    ll res=0;
    while(l<n)
    {
        if(r==n)
        {
            res+=(r-l);
            l++;
            continue;
        }
        int next=arr[r+1];
        if(alpha[next]>0)
        {
            r++;
            alpha[next]--;
        }
        else
        {
            if(l==r)
            {
                r++;
                l++;
                continue;
            }
            res+=(r-l);
            l++;
            alpha[arr[l]]++;
        }
    }
    cout<<res;
}