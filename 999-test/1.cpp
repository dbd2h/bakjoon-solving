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
    int n,k;
    cin>>n>>k;
    int two=1;
    int res=0;
    while(true)
    {
        int num=min(n/two,k);
        if(num==0) break;
        res+=num;
        n-=num*two;
        two*=2;
        
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