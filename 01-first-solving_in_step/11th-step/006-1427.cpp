#include <iostream>

int main()
{
    long long inputNum;
    std::cin>>inputNum;

    int numArr[10]={0};
    while(inputNum!=0)
    {
        numArr[inputNum%10]++;
        inputNum/=10;
    }
    for(int i=9;i>=0;i--)
    {
        while(numArr[i]!=0)
        {
            numArr[i]--;
            std::cout<<i;
        }
    }
    std::cout<<"\n";
}