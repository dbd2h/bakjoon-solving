#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 101

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[LEN][LEN];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cin>>arr[i][j];
    }
    int r,c,k;
    cin>>r>>c>>k;
    int res=0;
    for(int i=r;i<=n;i++)
    {
        for(int j=c;j<=n;j++)
        {
            int cur=arr[i][j];
            if(cur%k==0) continue;
            res+=cur;
        }
    }
    cout<<res;
}