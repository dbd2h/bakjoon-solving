#include <iostream>

void primeNumGetter(int *arr, int len)
{
    for(int i=2;i<len;i++)
    {
        bool isPrime=true;
        for(int j=0;j<i-1;j++)
        {
            if(arr[j]==0)
            {
                arr[j]=i;
                break;
            }
            if(i%arr[j]==0)
            {
                isPrime=false;
                break;
            }
        }
    }
}

int main()
{
    int primeArr[330]={0};
    primeNumGetter(primeArr, sizeof(primeArr)/sizeof(int));
    int primeAdd=0;
    int firstPrime=0;
    int start,end;
    std::cin>>start>>end;

    for(int i=start;i<=end;i++)
    {
        bool isPrime=true;
        for(int j=0;j<i;j++)
        {
            
            if(primeArr[j]==0)
            {
                break;
            }
            if((i!=primeArr[j]&&i%primeArr[j]==0)||i==1)
            {
                isPrime=false;
                break;
            }
        }
        if(isPrime)
        {
            if(firstPrime==0)
            {
                firstPrime=i;
            }
            primeAdd+=i;
        }
    }
    if(primeAdd==0)
    {
        std::cout<<-1<<std::endl;
    }
    else
    {
        std::cout<<primeAdd<<std::endl;
        std::cout<<firstPrime<<std::endl;
    }
    return 0;
}