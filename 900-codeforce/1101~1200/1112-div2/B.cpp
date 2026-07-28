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
    int n,k;
    cin>>n>>k;
    if(n-k<2)
    {
        cout<<-1<<"\n";
        return;
    }
    int l=k/2;
    int r=k-l;
    l++;
    r++;
    bool isZ=true;
    for(int i=0;i<l;i++) cout<<0;
    for(int i=0;i<r;i++) cout<<1;
    for(int i=l+r;i<n;i++)
    {
        if(isZ) cout<<0;
        else cout<<1;
        isZ=!isZ;
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