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

int cmp(int n1, int n2)
{
    return n1>n2;
}

void program()
{
    int n;
    cin>>n;
    int bit[1001]={0};
    int arr[50];
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        bit[num]++;
        arr[i]=num;
    }
    sort(arr,arr+n);
    int maxV=0;
    int maxN=0;
    for(int i=1;i<=1000;i++)
    {
        if(bit[i]==0) continue;
        if(maxV<bit[i])
        {
            maxV=bit[i];
            maxN=i;
        }
    }
    int res=min(n-maxV+2,maxV)*maxN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==maxN) continue;
        res+=arr[i];
    }
    cout<<res<<"\n";
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