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

void program()
{
    int n;
    cin>>n;
    int arr[3]={0};
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        arr[num]++;
    }
    int res=0;
    res+=arr[0];
    int minV=min(arr[1],arr[2]);
    arr[1]-=minV;
    arr[2]-=minV;
    res+=minV;
    res+=(arr[1]/3);
    res+=(arr[2]/3);
    cout<<res<<"\n";
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