#include <iostream>
#include <string>

long long multi(int num, int a)
{
    if(num==0)
    {
        return 1;
    }
    return multi(num-1,a)*a;
}

int main()
{
    int a,b,m;
    std::cin>>a>>b>>m;
    long long num=0;
    for(int i=m-1;i>=0;i--)
    {
        int iNum;
        std::cin>>iNum;
        num+=iNum*multi(i,a);
    }
    int len=0;
    int mMaker=1;
    while(num>=mMaker)
    {
        mMaker*=b;
        len++;
    }
    int numArr[len]={0};
    for(int i=0;i<len;i++)
    {
        numArr[i]=num%b;
        num/=b;
    }
    for(int i=len-1;i>=0;i--)
    {
        if(i==0)
        {
            std::cout<<numArr[i];
            break;
        }
        std::cout<<numArr[i]<<' ';
    }
    return 0;
}

