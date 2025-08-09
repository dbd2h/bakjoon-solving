#include <iostream>
#include <string>

using namespace std;

void problem()
{
    int n,x;
    cin>>n>>x;
    string s;
    cin>>s;
    int minV=-1;
    for(int i=x-2;i>=0;i--)
    {
        if(s[i]!='#') continue;
        minV=i+1;
        break;
    }
    int maxV=-1;
    for(int i=x;i<=n;i++)
    {
        if(s[i]!='#') continue;
        maxV=i+1;
        break;
    }
    int res=1;
    if(minV==-1 && maxV==-1)
    {
        res=1;
    }
    else if(minV==-1)
    {
        int l=x-1;
        int r=n-maxV+1;
        if(l>r) res=r+1;
        else res=l+1;
    }
    else if(maxV==-1)
    {
        int l=minV;
        int r=n-x;
        if(l>r) res=r+1;
        else res=l+1;
    }
    else
    {
        int l=minV;
        int r=n-maxV+1;
        if(l>r)
        {
            r=n-x;
        }
        else
        {
            l=x-1;
        }
        if(l>r) res=r+1;
        else res=l+1;
    }
    cout<<res<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        problem();
    }
}