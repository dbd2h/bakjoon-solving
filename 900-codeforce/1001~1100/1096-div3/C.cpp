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
    int div[LEN];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]%6==0)
        {
            div[i]=6;
        }
        else if(arr[i]%2==0)
        {
            div[i]=2;
        }
        else if(arr[i]%3==0)
        {
            div[i]=3;
        }
        else
        {
            div[i]=1;
        }       
    }
    int remArr[4]={6,2,1,3};
    for(int i=0;i<4;i++)
    {
        int rem=remArr[i];
        for(int j=0;j<n;j++)
        {
            if(div[j]!=rem) continue;
            cout<<arr[j]<<" ";
        }
    }
    cout<<"\n";
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