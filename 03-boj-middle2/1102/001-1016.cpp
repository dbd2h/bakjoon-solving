#include <iostream>

using namespace std;

int main()
{
    long long min,max;
    cin>>min>>max;
    bool primeArr[1000001]={0};
    primeArr[1]=1;
    for(int i=2;i<=1000000;i++)
    {
        if(primeArr[i]) continue;
        int idx=i*2;
        while(idx<=1000000)
        {
            primeArr[idx]=1;
            idx+=i;
        }
    }
    bool result[1000001]={0};
    long long finish=max-min;
    for(long long i=2;i<=1000000;i++)
    {
        if(primeArr[i]) continue;
        long long powNum=i*i;
        long long idx=powNum-min%powNum;
        idx%=powNum;
        while(idx<=finish)
        {
            result[idx]=1;
            idx+=powNum;
        }
    }
    int res=0;
    for(int i=0;i<=finish;i++)
    {
        if(result[i]) continue;
        res++;
    }
    cout<<res;
}