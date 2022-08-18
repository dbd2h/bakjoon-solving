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
    int primeArr[3300]={0};
    primeNumGetter(primeArr,3300);

    int input;
    std::cin>>input;

    for(int i=0;i<sizeof(primeArr)/sizeof(int);i++)
    {
        if(primeArr[i]==0)
        {
            std::cout<<input<<std::endl;
            break;
        }
        if(input==1)
        {
            break;
        }
        while(input%primeArr[i]==0)
        {
            std::cout<<primeArr[i]<<std::endl;
            input/=primeArr[i];
        }
    }
    return 0;
}