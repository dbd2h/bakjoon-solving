#include <iostream>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    int numArr[10000]={0};
    int inputNum;
    std::cin>>inputNum;

    for(int i=0;i<inputNum;i++)
    {
        int sortNum;
        std::cin>>sortNum;
        numArr[sortNum-1]++;
    }
    for(int i=0;i<sizeof(numArr)/sizeof(int);i++)
    {
        while(numArr[i]!=0)
        {
            std::cout<<i+1<<"\n";
            numArr[i]--;
        }
    }
    return 0;
}