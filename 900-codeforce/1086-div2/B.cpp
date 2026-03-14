#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
typedef long long ll;
typedef long double lld;

using namespace std;

void program()
{
    int n,k,p,m;
    cin>>n>>k>>p>>m;
    int arr[5000];
    int win=-1;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        if(i==p-1)
        {
            win=num;
            continue;
        }
        if(win==-1)
        {
            arr[i]=num;
        }
        else
        {
            arr[i-1]=num;
        }
    }
    int res=0;
    int energyUse=win;
    bool isF=false;
    if(k<p)
    {
        sort(arr,arr+p-1);
        for(int i=0;i<p-k;i++)
        {
            energyUse+=arr[i];
        }
        if(energyUse<=m) res++;
        else isF=true;
    }
    else
    {
        res++;
    }
    if(isF)
    {
        cout<<res<<"\n";
        return;
    }
    sort(arr,arr+n-1);
    int sumV=win;
    for(int i=0;i<n-k;i++)
    {
        sumV+=arr[i];
    }
    while(true)
    {
        energyUse+=sumV;
        if(energyUse>m) break;
        res++;
    }
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