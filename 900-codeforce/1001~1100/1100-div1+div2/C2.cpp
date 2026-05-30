#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
typedef long long ll;
typedef long double lld;

#define LEN 200001

using namespace std;

void program()
{
    int n;
    cin>>n;
    ll arr[LEN];
    ll sumArr[LEN];
    sumArr[0]=0;
    bool isM=false;
    int idx=n;
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        sumArr[i]=sumArr[i-1]+abs(arr[i]);
        res+=arr[i];
    }
    ll sumV=0;
    int resI=0;
    for(int i=n;i>=1;i--)
    {
        if(arr[i]<0)
        {
            sumV+=arr[i];
            continue;
        }
        ll cur=sumV-arr[i]+sumArr[i-1];
        if(cur>res)
        {
            resI=i;
            res=cur;
        }
        sumV+=arr[i];
    }
    vector<int> resV;
    isM=false;
    for(int i=resI-1;i>=1;i--)
    {
        if((!isM && arr[i]<0) || (isM && arr[i]>0)) continue;
        resV.push_back(i);
        isM=!isM;
    }
    if(resI!=0) resV.push_back(resI);
    int len=resV.size();
    cout<<len<<"\n";
    for(int i=0;i<len;i++) cout<<resV[i]<<" ";
    cout<<"\n";
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