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

int bit[26]={0};

int main()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    for(int i=0;i<n;i++)
    {
        bit[s[i]-'a']++;
    }
    for(int i=0;i<n;i++)
    {
        int cur=t[i]-'a';
        bit[cur]--;
        if(bit[cur]<0)
        {
            cout<<-1;
            return 0;
        }
    }
    int l=n-1;
    int r=n-1;
    while(r>=0)
    {
        if(s[l]==t[r]) l--;
        r--;
    }
    cout<<l+1;
}