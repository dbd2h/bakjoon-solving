#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 100001
#define INF (ll)(1e18)

using namespace std;

int moveArr[LEN*4]={0};

int moveF(int num)
{
    int idx=num;
    int cnt=0;
    if(moveArr[num]!=0) return moveArr[num];
    while(num)
    {
        if(num%2==1) num--;
        else num/=2;
        cnt++;
    }
    moveArr[idx]=cnt;
    return cnt;
}

void program()
{
    int n;
    cin>>n;
    int arr[LEN];
    ll res=INF;
    for(int i=0;i<n;i++) cin>>arr[i];
    int div=1;
    int c=0;
    while(div<LEN*2)
    {
        ll cur=c;
        for(int i=0;i<n;i++)
        {
            int num=arr[i];
            ll best=INF;
            while(num<LEN*2)
            {
                if(num%div==0)
                {
                    ll cur=num-arr[i]+moveF(num/div);
                    best=min(best,cur);
                }
                num+=num&-num;
            }
            cur+=best;
        }
        res=min(res,cur);
        div*=2;
        c++;
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