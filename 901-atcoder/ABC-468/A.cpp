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

int main()
{
    int n;
    cin>>n;
    int arr[100];
    int res=0;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=1;i<n-1;i++)
    {
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) res++;
    }
    cout<<res;
}