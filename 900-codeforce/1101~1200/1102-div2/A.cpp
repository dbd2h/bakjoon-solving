#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
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
    int arr[100];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n,cmp);
    bool isF=false;
    for(int i=0;i<n-2;i++)
    {
        if(arr[i]%arr[i+1]==arr[i+2]) continue;
        isF=true;
        break;
    }
    if(isF) cout<<-1<<"\n";
    else cout<<arr[0]<<" "<<arr[1]<<"\n";
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