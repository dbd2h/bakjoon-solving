#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    int isChangestart[500001]={0};
    int isChangeend[500001]={0};
    for(int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        isChangestart[l]++;
        isChangeend[r]++;
    }
    int sumV=0;
    for(int i=1;i<=n;i++)
    {
        sumV+=isChangestart[i];
        if(sumV%2==1) cout<<t[i-1];
        else cout<<s[i-1];
        sumV-=isChangeend[i];
    }
}