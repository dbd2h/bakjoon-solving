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
    bool isYes=false;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        if(num==100) isYes=true;
    }
    if(isYes) cout<<"YES\n";
    else cout<<"NO\n";
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