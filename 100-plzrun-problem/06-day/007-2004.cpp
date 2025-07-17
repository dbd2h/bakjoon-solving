#include <iostream>

int divFive(long long num)
{
    int count=0;
    while(num!=0)
    {
        count+=num;
        num/=5;
    }
    return count;
}

int divTwo(long long num)
{
    int count=0;
    while(num!=0)
    {
        count+=num;
        num/=2;
    }
    return count;
}

int min(int num1,int num2)
{
    if(num1>num2)
    {
        return num2;
    }
    else 
    {
        return num1;
    }
}

int main()
{
    long long n,m,result;
    std::cin>>n>>m;
    int res1,res2;
    res1=divFive(n)-divFive(m)-divFive(n-m);
    res2=divTwo(n)-divTwo(m)-divTwo(n-m);
    result=min(res1,res2);
    std::cout<<result<<"\n";
}