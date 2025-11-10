#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int arr[100000];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int num;
        cin>>num;
        int res=binary_search(arr,arr+n,num);
        cout<<res<<"\n";
    }
}