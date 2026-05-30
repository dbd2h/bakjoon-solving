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
    int arr[LEN];
    for(int i=1;i<=n;i++) cin>>arr[i];
    vector<int> resV;
    bool isM=false;
    for(int i=n;i>=1;i--)
    {
        if((!isM && arr[i]<0) || (isM && arr[i]>0)) continue;
        resV.push_back(i);
        isM=!isM;
    }
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