#include <iostream>

int gcd(int num1, int num2)
{
    if(num1%num2==0)
    {
        return num2;
    }
    return gcd(num2,num1%num2);
}

int main()
{
    int count;
    std::cin>>count;
    for(int a=0;a<count;a++)
    {
        int n;
        std::cin>>n;
        int numArr[n];
        for(int i=0;i<n;i++)
        {
            std::cin>>numArr[i];
        }
        long long total=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int num1=numArr[i];
                int num2=numArr[j];
                if(num1>num2)
                {
                    total+=gcd(num1,num2);
                }
                else
                {
                    total+=gcd(num2,num1);
                }
            }
        }
        std::cout<<total<<"\n";
    }
    return 0;
}