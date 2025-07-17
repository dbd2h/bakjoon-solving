#include <iostream>

using namespace std;

int countV=0;

void binaryMaker(int binary[], int n)
{
    if(n!=1)
    {
        binaryMaker(binary, n/2);
        
    }
    binary[countV]=n%2;
    countV++;
}

int remain(long long i, long long a, long long c)
{
    for(int j=0;j<countV-i-1;j++)
    {
        a=(a*a)%c;
        
    }
    return a;
}

int main()
{
    int binary[31]={0};
    long long a,b,c;
    cin>>a>>b>>c;
    binaryMaker(binary, b);
    long long result=1;
    for(int i=0;i<countV;i++)
    {
        if(binary[i]==1)
        {
            result*=remain(i, a, c);
            result%=c;
        }
    }
    cout<<result;
}