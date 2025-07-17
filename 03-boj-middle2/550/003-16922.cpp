#include <iostream>

using namespace std;

int bit[1001]={0};

void roma(int n, int c, int s, int num)
{
    if(c==3)
    {
        bit[num+50*(n-s)]=1;
        return;
    }
    for(int i=0;i<=n-s;i++)
    {
        int snum;
        if(c==0) snum=1;
        else if(c==1) snum=5;
        else if(c==2) snum=10;
        roma(n, c+1, s+i, num+i*snum);
    }
}

int main()
{
    int n;
    cin>>n;
    int res=0;
    roma(n,0,0,0);
    for(int i=1;i<=1000;i++)
    {
        if(bit[i]==0) continue;
        res++;
    }
    cout<<res;
}