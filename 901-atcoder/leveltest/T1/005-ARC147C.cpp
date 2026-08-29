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
#define INF (ll)(1e18)

using namespace std;
vector<ll> leftV;
vector<ll> rightV;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        leftV.push_back(l);
        rightV.push_back(r);
    }
    sort(leftV.begin(),leftV.end(),greater<>());
    sort(rightV.begin(),rightV.end());
    ll res=0;
    for(int i=0;i<n;i++) res+=max(0LL,leftV[i]-rightV[i])*(n-i*2-1);
    cout<<res;
}