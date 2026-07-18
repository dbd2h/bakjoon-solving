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
#define LEN 200001

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int A[LEN],B[LEN];
    for(int i=0;i<n;i++) cin>>A[i];
    for(int i=0;i<n-1;i++) cin>>B[i];
    int res=2000000;
    // start:0
    int sumV=0;
    int s=0;
    for(int i=0;i<n-1;i++)
    {
        int cur=(A[i]+A[i+1]+s)%m;
        s=(B[i]-cur+m)%m;
        sumV+=s;
    }
    res=sumV;
    sumV=1;
    s=1;
    for(int i=0;i<n-1;i++)
    {
        int cur=(A[i]+A[i+1]+s)%m;
        s=(B[i]-cur+m)%m;
        sumV+=s;
    }
    res=min(res,sumV);
    cout<<res;
}