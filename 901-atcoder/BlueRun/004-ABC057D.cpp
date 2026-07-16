#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 51

using namespace std;

ll combi[LEN][LEN];

int cmp(ll a, ll b)
{
    return a>b;
}

int main()
{
    for(int i=0;i<LEN;i++) combi[i][0]=combi[i][i]=1;
    for(int i=2;i<LEN;i++)
    {
        for(int j=1;j<i;j++)
        {
            combi[i][j]=combi[i-1][j-1]+combi[i-1][j];
        }
    }
    int n,a,b;
    cin>>n>>a>>b;
    ll arr[LEN];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n,cmp);
    ll maxV=arr[0];
    ll sumV=0;
    for(int i=0;i<a;i++)
    {
        sumV+=arr[i];
    }
    cout<<fixed;
    cout.precision(9);
    cout<<(lld)sumV/a<<"\n";
    ll cur=arr[a-1];
    int c=0;
    int idx=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==cur)
        {
            c++;
            if(idx==-1) idx=i;
        }
    }
    int len=a-idx;
    if(idx==0)
    {
        ll res=0;
        for(int i=a;i<=min(b,c);i++)
        {
            res+=combi[c][i];
        }
        cout<<res;
    }
    else if(c>len)
    {
        cout<<combi[c][len];
    }
    else
    {
        cout<<1;
    }
}

// time: 19M 00S Solve
// 1. 신호: 배열에서 값들의 평균이 최대가 되도록 더하기 -> 큰 값부터 더한다면 어느 값을 더했을 시 평균은 같거나 작아짐
// 2. 도구: 똑같은 값이 a개 이상 있는거 아니면 큰 값 a개 골라서 더하는게 최대. 그리고 케이스 나뉘는거 신경 써주면 됨
// 3. 막힌 지점: 