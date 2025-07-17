#include <iostream>
#include <string>

using namespace std;

int aArr[10]={0};
int bit[10]={0};

void number(int n, int b, int c, int *maxnum, int cnum)
{
    if(n==c)
    {
        if(cnum<b && cnum>*maxnum) *maxnum=cnum;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(bit[i]==1 || c==n-1 && aArr[i]==0) continue;
        int ten=1;
        for(int j=0;j<c;j++)
        {
            ten*=10;
        }
        bit[i]=1;
        number(n,b,c+1,maxnum,cnum+aArr[i]*ten);
        bit[i]=0;
    }
}

int main()
{
    string a;
    int b;
    cin>>a>>b;
    int n=a.length();
    for(int i=0;i<n;i++)
    {
        aArr[i]=a[i]-'0';
    }
    int maxV=-1;
    number(n,b,0,&maxV,0);
    cout<<maxV;
}