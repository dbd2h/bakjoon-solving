#include <iostream>

int primeMaker(int arr[])
{
    int len=0;
    for(int i=3;i<1000;i+=2)
    {
        bool isPrime=true;
        for(int j=0;j<len;j++)
        {
            if(i%arr[j]==0)
            {
                isPrime=false;
                break;
            }
        }
        if(isPrime)
        {
            arr[len]=i;
            len++;
        }
    }
    return len;
}

int main()
{
    int primeArr[500];
    int len;
    len=primeMaker(primeArr);
    int n;
    std::cin.tie(NULL);
    while(true)
    {
        std::cin>>n;
        if(n==0)
        {
            break;
        }
        for(int i=0;i<len;i++)
        {
            int b=n-primeArr[i];
            bool isPrime=true;
            for(int j=0;j<len;j++)
            {
                if(b==primeArr[j])
                {
                    break;
                }
                if(b%primeArr[j]==0)
                {
                    isPrime=false;
                }
            }
            if(isPrime)
            {
                std::cout<<n<<" = "<<primeArr[i]<<" + "<<b<<"\n";
                break;
            }
        }
    }
}