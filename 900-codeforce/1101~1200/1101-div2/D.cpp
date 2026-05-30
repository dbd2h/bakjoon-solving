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

vector<pair<int,pair<int,int>>> resV;

void hanoi(int arr[], int n, int from, int to)
{
    if(n==0)
    {
        return;
    }
    int mid=6-from-to;
    if(arr[n]==0)
    {
        hanoi(arr,n-1,from,mid);
        resV.push_back({n,{from,to}});
        hanoi(arr,n-1,mid,to);
    }
    else
    {
        hanoi(arr,n-1-arr[n],from,mid);
        resV.push_back({n,{from,to}});
        hanoi(arr,n-1-arr[n],mid,from);
        hanoi(arr,n-1,from,to);
    }
}

void program()
{
    int n;
    cin>>n;
    int arr[21];
    bool isNo=false;
    resV.clear();
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i]+1>i) isNo=true;
        if(isNo) continue;
    } 
    if(isNo)
    {
        cout<<"NO\n";
        return;
    }
    hanoi(arr,n,1,3);
    cout<<"YES\n";
    cout<<resV.size()<<"\n";
    for(auto &p : resV)
    {
        cout<<p.first<<" "<<p.second.first<<" "<<p.second.second<<"\n";
    }
    
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