#include<iostream>

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
    int primeArr[34]={0};
    int totalPrime=0;
    int count;
    primeNumGetter(primeArr,sizeof(primeArr)/sizeof(int));

    std::cin>>count;

    for(int i=0;i<count;i++)
    {
        int inputNum;
        std::cin>>inputNum;
        for(int j=0;j<inputNum;j++)
        {
            if(primeArr[j]==0)
            {
                break;
            }
            if((inputNum!=primeArr[j]&&inputNum%primeArr[j]==0)||inputNum==1)
            {
                totalPrime--;
                break;
            }
        }
        totalPrime++;
    }
    std::cout<<totalPrime<<std::endl;
}