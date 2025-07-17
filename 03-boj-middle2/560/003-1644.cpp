#include <iostream>

using namespace std;

int primeArr[2000000]={0};
int teratos[4000001]={0};

void prime(int n, int *c)
{
    for(int i=2;i<n;i++)
    {
        if(teratos[i]==1) continue;
        if(i*i>n) break;
        for(int j=2;j<n;j++)
        {
            if(i!=2 && j%2==0) continue;
            if(i*j>n) break;
            teratos[i*j]=1;
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(teratos[i]==1) continue;
        primeArr[*c]=i;
        (*c)++;
    }
}

int main()
{
    int n;
    cin>>n;
    int c=0;
    prime(n,&c);
    int pl,de;
    pl=0;
    de=0;
    int res=0;
    int sumV=0;
    while(true)
    {
        if(pl==c && sumV<n) break;
        if(sumV<n)
        {
            sumV+=primeArr[pl];
            pl++;
        }
        else if(sumV>n)
        {
            sumV-=primeArr[de];
            de++;
        }
        else if(sumV==n)
        {
            res++;
            sumV-=primeArr[de];
            de++;
        }
    }
    cout<<res;
}