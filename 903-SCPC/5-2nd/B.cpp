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
#define LEN 5001

using namespace std;

int A[LEN];
int B[LEN];

void program()
{
    int n;
    cin>>n;
    int sumV=0;
    for(int i=1;i<=n;i++) cin>>A[i];
    for(int i=1;i<=n;i++)
    {
        cin>>B[i];
        if(A[i]==B[i]) sumV++;
    }
    int res=sumV;
    for(int i=1;i<=n;i++)
    {
        int l=i;
        int r=i+1;
        int cur=sumV;
        while(l>=1 && r<=n)
        {
            if(A[l]==B[l]) cur--;
            if(A[r]==B[r]) cur--;
            if(A[l]==B[r]) cur++;
            if(A[r]==B[l]) cur++;
            res=max(res,cur);
            l--;
            r++;
        }
        l=i;
        r=i+2;
        cur=sumV;
        while(l>=1 && r<=n)
        {
            if(A[l]==B[l]) cur--;
            if(A[r]==B[r]) cur--;
            if(A[l]==B[r]) cur++;
            if(A[r]==B[l]) cur++;
            res=max(res,cur);
            l--;
            r++;
        }
    }
    cout<<res<<endl;
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