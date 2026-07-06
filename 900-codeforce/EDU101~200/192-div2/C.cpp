#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 300001

using namespace std;

int bit[LEN]={0};

void program()
{
    ll n,k;
    cin>>n>>k;
    ll sumV=n;
    for(int i=1;i<=n;i++) bit[i]=0;
    for(int i=1;i<=n;i++)
    {
        int num;
        cin>>num;
        bit[num]++;
    }
    vector<int> v;
    for(int i=1;i<=n;i++)
    {
        if(bit[i]==0) continue;
        v.push_back(bit[i]);
    }
    sort(v.begin(), v.end());
    int len=v.size();
    int sub=0;
    int res=0;
    n=len;
    for(int i=0;i<len;i++)
    {
        int cur=v[i]-1;
        int c=0;
        while(i<len && v[i]-1==cur)
        {
            c++;
            i++;
        }
        i--;
        sumV-=n*(cur-sub);
        if(sumV<=k && (k-sumV)%n==0) res++;
        sumV-=n;
        n-=c;
        sub=v[i];
    }
    cout<<res<<"\n";

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