#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

void program()
{
    int n,m;
    cin>>n>>m;
    int arr[100000]={0};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    long long result=0;
    for(int i=n-1;i>=0;i--)
    {
        if(m-(n-i-1)<=0) break;
        result += (long long) arr[i] * (long long) (m-(n-i-1));
    }
    cout<<result<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}