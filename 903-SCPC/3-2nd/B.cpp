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

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

void program()
{
    int n;
    cin>>n;
    ll arr[5][3];
    ll tArr[5][2];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][2]>>arr[i][1];
        ll gcdV=gcd(arr[i][0],arr[i][1]);
        gcdV=gcd(gcdV,arr[i][2]);
        arr[i][0]/=gcdV;
        arr[i][1]/=gcdV;
        arr[i][2]/=gcdV;
        ll t=0;
        tArr[i][0]=arr[i][2];
        for(int j=1;j<=arr[i][2];j++)
        {
            if((arr[i][0]*j+arr[i][1])%arr[i][2]==0)
            {
                tArr[i][1]=j;
                break;
            }
        }
    }
    ll resA=tArr[0][0];
    ll resB=tArr[0][1];
    for(int i=1;i<n;i++)
    {
        ll curA=tArr[i][0];
        ll curB=tArr[i][1];
        for(int j=0;j<curA;j++)
        {
            if(resA*j+resB<=0) continue;
            ll num=resA*j+resB-curB;
            if(num<0) continue;
            if(num%curA==0)
            {
                resB=resA*j+resB;
                break;
            }
        }
        resA=resA/gcd(resA,curA);
        resA*=curA;
    }
    cout<<resB<<"\n";
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