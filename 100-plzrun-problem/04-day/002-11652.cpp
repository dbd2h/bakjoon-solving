#include <iostream>
#include <algorithm>

int main()
{
    int inputNum;
    std::cin>>inputNum;
    long long numArr[inputNum];
    for(int i=0;i<inputNum;i++)
    {
        std::cin>>numArr[i];
    }
    std::sort(numArr,numArr+inputNum);
    int max=1;
    long long maxNum=numArr[0];
    long long preNum=numArr[0];
    int cnt=1;
    for(int i=1;i<inputNum;i++)
    {
        if(preNum==numArr[i])
        {
            cnt+=1;
            if(cnt>max)
            {
                max=cnt;
                maxNum=numArr[i];
            }
        }
        else
        {
            cnt=1;
            preNum=numArr[i];
        }
    }
    std::cout<<maxNum<<"\n";
}