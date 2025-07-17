#include <iostream>

int divFive(int num)
{
    int count=0;
    while(num%5==0)
    {
        count++;
        num/=5;
    }
    return count;
}

int main()
{
    int n;
    std::cin>>n;
    int total=0;
    for(int i=1;i<=n;i++)
    {
        total+=divFive(i);
    }
    std::cout<<total<<"\n";
}