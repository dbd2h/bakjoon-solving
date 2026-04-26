#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
typedef long long ll;
typedef long double lld;

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n*2;i++)
    {
        for(int j=0;j<n*2;j++)
        {
            if(n*2-j==i) cout<<"*";
            else cout<<" ";
        }
        cout<<" ";
        int idx;
        if(i<=n) idx=n-i;
        else idx=i-n-1;
        for(int i=0;i<idx;i++) cout<<" ";
        cout<<"*";
        for(int i=0;i<(n-idx)*2-1;i++) cout<<" ";
        cout<<"*";
        for(int i=0;i<idx;i++) cout<<" ";
        cout<<"\n";
    }
}