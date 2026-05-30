#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
typedef long long ll;
typedef long double lld;

using namespace std;

int resF(int num, int arr[], int n)
{
    bool isPos=true;
    int res=0;
    for(int i=0;i<n;i++)
    {
        int cur=arr[i];
        if(cur==num) continue;
        while(true)
        {
            res++;
            if(cur%2==1) cur+=1;
            else
            {
                if(cur<num)
                {
                    isPos=false;
                    break;
                }
                cur/=2;
            }
            if(cur==num) break;
        }
        if(!isPos) break;
    }
    if(!isPos) return -1;
    return res;
}

void program()
{
    int n;
    cin>>n;
    int arr[100000];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    vector<int> v;
    int num=arr[0];
    while(num!=1)
    {
        v.push_back(num);
        if(num%2==1) num++;
        else num/=2;
    }
    v.push_back(1);
    if(v.size()==1) v.push_back(2);
    int res=1e9;
    for(auto&num : v)
    {
        int resV=resF(num,arr,n);
        if(resV==-1) continue;
        res=min(res,resV);
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