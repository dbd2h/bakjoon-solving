#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 200005

using namespace std;

ll blueH[LEN], redH[LEN], blueS[LEN], redS[LEN];
ll bluePr[LEN], blueSu[LEN], redPr[LEN], redSu[LEN];


void program()
{
    int n,r;
    cin>>n>>r;
    bluePr[0]=0;
    redPr[0]=0;
    blueSu[n-r+1]=0;
    redSu[r+2]=0;
    for(int i=1;i<=n-r;i++) cin>>blueH[i];
    for(int i=1;i<=r;i++) cin>>redH[i];
    for(int i=1;i<=n-r-1;i++) cin>>blueS[i];
    for(int i=1;i<=r+1;i++) cin>>redS[i];
    sort(blueH+1,blueH+n-r+1);
    sort(blueS+1,blueS+n-r);
    sort(redH+1,redH+r+1);
    sort(redS+1,redS+r+2);
    for(int i=1;i<=n-r-1;i++) bluePr[i]=bluePr[i-1]+abs(blueH[i]-blueS[i]);
    for(int i=n-r;i>=2;i--) blueSu[i]=blueSu[i+1]+abs(blueH[i]-blueS[i-1]);
    for(int i=1;i<=r;i++) redPr[i]=redPr[i-1]+abs(redH[i]-redS[i]);
    for(int i=r+1;i>=2;i--) redSu[i]=redSu[i+1]+abs(redH[i-1]-redS[i]);
    ll res=1e18;
    for(int i=1;i<=n-r;i++)
    {
        ll cur=bluePr[i-1]+blueSu[i+1];
        int left=1;
        int right=r;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(redH[mid]<blueH[i]) left=mid+1;
            else right=mid-1;
        }
        cur+=(redPr[left-1]+redSu[left+1]+abs(blueH[i]-redS[left]));
        res=min(res,cur);
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
        cout<<"Case #"<<i<<"\n";
        program();
    }
}