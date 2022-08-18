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

    const int len=100;
    int primeArr[len]={0};
    primeNumGetter(primeArr,len);

    int test;
    std::cin>>test;

    for(int i=0;i<test;i++)
    {
        int evenNum;
        std::cin>>evenNum;
        int min,max;
        min=evenNum/2;
        max=evenNum/2;
        if(min%2==0&&min!=2)
        {
            min--;
            max++;
        }

        while(true)
        {
            bool isPrime=true;
            for(int j=0;primeArr[j]<max;j++)
            {
                if(primeArr[j]==0)
                {
                    break;
                }
                if((min%primeArr[j]==0&&min!=primeArr[j])||(max%primeArr[j]==0&&max!=primeArr[j]))
                {
                    isPrime=false;
                    break;
                }
            }
            if(isPrime)
            {
                break;
            }
            else
            {
                min-=2;
                max+=2;
            }
        }
        std::cout<<min<<" "<<max<<"\n";
    }
}