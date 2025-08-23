#include <iostream>
#include <vector>
#define LEN 4000000

using namespace std;

int combi[LEN]={0};

bool prime[LEN+1]={0};
vector<int> primeV;

long long powValue(long long n, long long i, long long m)
{
    if(i==1) return n;
    long long reV=powValue((n*n)%m,i/2,m);
    reV%=m;
    if(i%2==1) return (reV*n)%m;
    else return reV;
}


void combiMaker(int s, bool isUp)
{
    for(int i=0;i<primeV.size();i++)
    {
        int sumV=0;
        long long num=primeV[i];
        if(num>s) break;
        while(true)
        {
            if(s/num==0) break;
            sumV+=(s/num);
            num*=(long long) primeV[i];
        }
        if(isUp) combi[primeV[i]]+=sumV;
        else combi[primeV[i]]-=sumV;
    }
}

int main()
{
    long long n,k,m;
    cin>>n>>k>>m;
    for(int i=2;i<=n;i++)
    {
        if(prime[i]) continue;
        primeV.push_back(i);
        for(int j=i*2;j<LEN;j+=i) prime[j]=true;
    }
    combiMaker(n,true);
    combiMaker(n-k,false);
    combiMaker(k,false);
    long long result=1;
    for(long long i=2;i<=n;i++)
    {
        if(!combi[i]) continue;
        result*=powValue(i,(long long)combi[i],m);
        result%=m;
    }
    cout<<result;
}