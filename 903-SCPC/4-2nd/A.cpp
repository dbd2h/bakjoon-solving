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
int sortArr[LEN];

void program()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sortArr[i]=arr[i];
    } 
    sort(sortArr,sortArr+n);
    int res=0;
    int maxV=0;
    for(int i=0;i<n;i++)
    {
        if(sortArr[i]==arr[i] && maxV<arr[i]) res++;
        maxV=max(maxV,arr[i]);
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