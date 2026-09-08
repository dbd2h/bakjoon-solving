#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
typedef long long ll;
typedef long double lld;

using namespace std;

void program()
{
    int n;
    cin>>n;
    int zero=0;
    int res=0;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        if(num==0)
        {
            zero++;
        }
        if(i==0 || i==n-1)
        {
            if(num==1) res++;
        }
    }
    if(zero<2) cout<<-1<<"\n";
    else cout<<res<<"\n";
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