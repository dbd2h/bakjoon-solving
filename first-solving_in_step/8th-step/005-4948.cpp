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
    const int len=600;
    int primeArr[len]={0};
    primeNumGetter(primeArr,len);

    while(true)
    {
        int n;
        std::cin>>n;
        if(n==0)
        {
            break;
        }
        int total=0;

        for(int i=n+1;i<=2*n;i++)
        {
            for(int j=0;primeArr[j]<i;j++)
            {
                if(primeArr[j]==0)
                {
                    break;
                }
                if((i%primeArr[j]==0&&i!=primeArr[j])||i==1)
                {
                    total--;
                    break;
                }
            }
            total++;
        }
        std::cout<<total<<std::endl;
    }
}