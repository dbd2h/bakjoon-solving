#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void program()
{
    int n,k;
    cin>>n>>k;
    int sArr[200000]={0};
    int tArr[200000]={0};
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        num%=k;
        if(num*2>k) num=-(num-k);
        sArr[i]=num;
    }
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        num%=k;
        if(num*2>k) num=-(num-k);
        tArr[i]=num;
    }
    sort(sArr,sArr+n);
    sort(tArr,tArr+n);
    bool isF=false;
    for(int i=0;i<n;i++)
    {
        if(sArr[i]!=tArr[i])
        {
            isF=true;
            break;
        }
    }
    if(!isF) cout<<"YES\n";
    else cout<<"NO\n";
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