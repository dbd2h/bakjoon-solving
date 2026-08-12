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
ll sumArr[LEN];

int main()
{
    int n,q;
    cin>>n>>q;
    sumArr[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        sumArr[i]=sumArr[i-1]+arr[i];
    } 
    for(int i=0;i<q;i++)
    {
        int sign;
        cin>>sign;
        if(sign==1)
        {
            int x;
            cin>>x;
            sumArr[x]-=arr[x];
            int c=arr[x];
            arr[x]=arr[x+1];
            arr[x+1]=c;
            sumArr[x]+=arr[x];
        }
        else if(sign==2)
        {
            int l,r;
            cin>>l>>r;
            cout<<sumArr[r]-sumArr[l-1]<<"\n";
        }
    }
}