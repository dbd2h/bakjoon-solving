#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

#define LEN 200001

using namespace std;

void program()
{
    int n;
    cin>>n;
    int arr[LEN];
    int zero1=-1;
    int zero2=-1;
    vector<int> v1,v2,v3;
    for(int i=0;i<2*n;i++)
    {
        cin>>arr[i];
        if(arr[i]==0)
        {
            if(zero1==-1) zero1=i;
            else if(zero2==-1) zero2=i;
        }
    }
    int res=0;
    for(int i=zero1;i<2*n;i++)
    {
        int l=zero1-(i-zero1);
        if(l<0) break;
        if(arr[l]!=arr[i]) break;
        v1.push_back(arr[i]);
    }
    sort(v1.begin(),v1.end());
    int cur=0;
    for(int i=0;i<v1.size();i++)
    {
        if(v1[i]==i) cur++;
        else break;
    }
    res=max(res,cur);

    for(int i=zero2;i<2*n;i++)
    {
        int l=zero2-(i-zero2);
        if(l<0) break;
        if(arr[l]!=arr[i]) break;
        v2.push_back(arr[i]);
    }
    sort(v2.begin(),v2.end());
    cur=0;
    for(int i=0;i<v2.size();i++)
    {
        if(v2[i]==i) cur++;
        else break;
    }
    res=max(res,cur);

    int l=zero1;
    int r=zero2;
    bool isP=true;
    while(l<=r)
    {
        if(arr[l]!=arr[r])
        {
            isP=false;
            break;
        }
        v3.push_back(arr[l]);
        l++;
        r--;
    }
    if(isP)
    {
        l=zero1-1;
        r=zero2+1;
        while(l>=0 && r<n*2)
        {
            if(arr[l]!=arr[r])
            {
                break;
            }
            v3.push_back(arr[l]);
            l--;
            r++;
        }
        sort(v3.begin(),v3.end());
        cur=0;
        for(int i=0;i<v3.size();i++)
        {
            if(v3[i]==i) cur++;
            else break;
        }
        res=max(res,cur);
    }
    cout<<res<<"\n";
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