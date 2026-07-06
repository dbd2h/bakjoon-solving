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
    int arr[10];
    for(int i=0;i<n;i++) cin>>arr[i];
    bool isTwo=false;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>=3)
        {
            cout<<"YES\n";
            return;
        }
        else if(arr[i]==2)
        {
            if(!isTwo) isTwo=true;
            else
            {
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";
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