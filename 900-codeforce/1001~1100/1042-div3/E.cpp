#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void program()
{
    int n;
    cin>>n;
    int aArr[200000]={0};
    int bArr[200000]={0};
    for(int i=0;i<n;i++)
    {
        cin>>aArr[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>bArr[i];
    }
    if(aArr[n-1]!=bArr[n-1])
    {
        cout<<"NO\n";
        return;
    }
    bool isFail=false;
    for(int i=n-2;i>=0;i--)
    {
        if(aArr[i]==bArr[i]) continue;
        if((aArr[i]^aArr[i+1])==bArr[i] || (aArr[i]^bArr[i+1])==bArr[i]) continue;
        
        isFail=true;
        break;
    }
    if(isFail) cout<<"NO\n";
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