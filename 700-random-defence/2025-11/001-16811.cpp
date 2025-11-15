#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
    ll a,b,c,n;
    cin>>a>>b>>c>>n;
    ll tot=0;
    tot+=a*b*2;
    tot+=b*c*2;
    tot+=a*c*2;
    int arr[1000][3];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int x1=arr[i][0];
            int y1=arr[i][1];
            int z1=arr[i][2];
            int x2=arr[j][0];
            int y2=arr[j][1];
            int z2=arr[j][2];
            if(x1==x2 && y1==y2 && (z1-z2==1 || z2-z1==1))
            {
                tot-=2;
            }
            if(x1==x2 && z1==z2 && (y1-y2==1 || y2-y1==1))
            {
                tot-=2;
            }
            if(z1==z2 && y1==y2 && (x1-x2==1 || x2-x1==1))
            {
                tot-=2;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        tot+=6;
        int x1=arr[i][0];
        int y1=arr[i][1];
        int z1=arr[i][2];
        if(x1==0)
        {
            tot-=2;
        }
        if(x1==a-1)
        {
            tot-=2;
        }
        if(y1==0)
        {
            tot-=2;
        }
        if(y1==b-1)
        {
            tot-=2;
        }
        if(z1==0)
        {
            tot-=2;
        }
        if(z1==c-1)
        {
            tot-=2;
        }
    }
    cout<<tot;
}