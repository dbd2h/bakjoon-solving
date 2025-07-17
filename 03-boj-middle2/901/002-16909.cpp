#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin>>n;
    long long arr[1000000]={0};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    long long result=0;
    stack<pair<long long,long long>> st1, st2, st3, st4;
    vector<long long> maxH, maxW, minH, minW;
    for(int i=0;i<n;i++)
    {
        while(!st1.empty() && st1.top().first<arr[i]) st1.pop();
        if(st1.empty()) maxH.push_back(i+1);
        else maxH.push_back(i-st1.top().second);
        st1.push({arr[i],i});
    }
    for(int i=0;i<n;i++)
    {
        while(!st2.empty() && st2.top().first<=arr[n-i-1]) st2.pop();
        if(st2.empty()) maxW.push_back(i+1);
        else maxW.push_back(i-st2.top().second);
        st2.push({arr[n-i-1],i});
    }
    for(int i=0;i<n;i++)
    {
        while(!st3.empty() && st3.top().first>arr[i]) st3.pop();
        if(st3.empty()) minH.push_back(i+1);
        else minH.push_back(i-st3.top().second);
        st3.push({arr[i],i});
    }
    for(int i=0;i<n;i++)
    {
        while(!st4.empty() && st4.top().first>=arr[n-i-1]) st4.pop();
        if(st4.empty()) minW.push_back(i+1);
        else minW.push_back(i-st4.top().second);
        st4.push({arr[n-i-1],i});
    }
    for(int i=0;i<n;i++)
    {
        result+=maxH[i]*maxW[n-i-1]*arr[i];
        result-=minH[i]*minW[n-i-1]*arr[i];
    }
    cout<<result;
}



// 1 9 3 2 0 10 7 4 3 2 1