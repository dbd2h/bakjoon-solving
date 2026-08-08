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
int arr[LEN];

void program()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    int bef=arr[1];
    int c=1;
    int res=1;
    for(int i=2;i<=n;i++)
    {
        if(arr[i]!=bef)
        {
            bef=arr[i];
            res++;
        } 
        c++;
    }
    int addV=0;
    for(int i=1;i<=n-1;i++)
    {
        if(arr[i]==arr[i+1]) continue;
        int cur=1;
        int befN=arr[max(i-1,1)];
        for(int j=max(i-1,1);j<=min(i+2,n);j++)
        {
            if(arr[j]!=befN)
            {
                cur++;
                befN=arr[j];
            }
        }
        int ch=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=ch;
        int next=1;
        befN=arr[max(i-1,1)];
        for(int j=max(i-1,1);j<=min(i+2,n);j++)
        {
            if(arr[j]!=befN)
            {
                next++;
                befN=arr[j];
            }
        }
        addV=max(addV,next-cur);
        ch=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=ch;
    }
    cout<<res+addV<<"\n";
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