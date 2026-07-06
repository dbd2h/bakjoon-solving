#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 200001

using namespace std;

int arr[LEN];

void program()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    int idx=0;
    int sum1=0;
    while(idx<n)
    {
        int cur=arr[idx];
        if(sum1>=0 && idx!=0)
        {
            while(idx<n && sum1>0 && cur==3)
            {
                idx++;
                if(idx<n) cur=arr[idx];
                sum1--;
            }
            break;
        }
        if(cur==1) sum1++;
        else sum1--;
        idx++;
    }
    int sum2=0;
    while(idx<n)
    {
        int cur=arr[idx];
        if(cur==3) sum2--;
        else sum2++;
        idx++;
        if(sum2>=0) break;
        
    }
    if(idx<n) cout<<"YES\n";
    else cout<<"NO\n";
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