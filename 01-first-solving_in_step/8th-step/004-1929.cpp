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
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int primeArr[3300]={0};
    primeNumGetter(primeArr,3300);

    int min,max;
    std::cin>>min>>max;

    for(int count=min;count<=max;count++)
    {
        bool isPrime=true;
        for(int j=0;primeArr[j]<count;j++)
        {
            if(primeArr[j]==0)
            {
                break;
            }
            if(count%primeArr[j]==0)
            {
                isPrime=false;
                break;
            }
        }
        if(isPrime&&count!=1)
        {
            std::cout<<count<<"\n";
        }
    }
}