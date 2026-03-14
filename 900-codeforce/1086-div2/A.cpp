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
    int n;
    cin>>n;
    int bit[10001]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int num;
            cin>>num;
            bit[num]++;
        }
    }
    bool isF=false;
    for(int i=1;i<=n*n;i++)
    {
        if(bit[i]>n*(n-1))
        {
            isF=true;
            break;
        }
    }
    if(isF) cout<<"NO\n";
    else cout<<"YES\n";
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