#include <iostream>

using namespace std;

int bit[10]={0};
long long mArr[10]={0};
void combi(int n, long long m, long long *result, int c)
{
    long long divV=1;
    int count=0;
    if(n==c)
    {
        for(int i=0;i<n;i++)
        {
            if(!bit[i]) continue;
            divV*=mArr[i];
            count++;
        }
        if(count==0) return;
        if(count%2==1)
        {
            *result += m/divV;
            return;
        }
        else
        {
            *result -= m/divV;
            return;
        }
    }
    combi(n,m,result,c+1);
    bit[c]=1;
    combi(n,m,result,c+1);
    bit[c]=0;
}

int main()
{
    int n;
    long long m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>mArr[i];
    }
    long long result=0;
    combi(n,m,&result,0);
    cout<<result;
}