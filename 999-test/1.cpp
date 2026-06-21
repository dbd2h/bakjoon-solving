#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

#define LEN 100000

using namespace std;

void program()
{
    int n;
    cin>>n;
    int arr[2][LEN];
    for(int i=0;i<n;i++) cin>>arr[0][i];
    for(int i=0;i<n;i++) cin>>arr[1][i];
    int l=1;
    int r=n*2;
    while(l<=r)
    {
        bool bitArr[2][LEN];
        int middle=(l+r)/2;
        for(int i=0;i<n*2;i++)
        {
            if(arr[i/n][i%n]>=middle) bitArr[i/n][i%n]=1;
            else bitArr[i/n][i%n]=0;
        }
        int c=0;
        bool befZero=0;
        for(int i=0;i<n;i++)
        {
            int cur=bitArr[0][i]+bitArr[1][i];

            if(cur==1) continue;
            else if(cur==0)
            {
                if(befZero) continue;
                befZero=1;
                c--;
            }
            else if(cur==2)
            {
                c++;
                befZero=0;
            }
        }
        if(c>0) l=middle+1;
        else r=middle-1;
    }
    cout<<l-1<<"\n";
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