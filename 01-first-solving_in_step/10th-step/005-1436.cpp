#include <iostream>

int main()
{
    int jariArr[10]={0};
    int n,result;
    std::cin>>n;
    int count=0;

    for(int i=666;i<1000000000;i++)
    {
        int index=0;
        int num=i;
        result=i;
        while(num>0)
        {
            jariArr[index]=num%10;
            index++;
            num=num/10;
        }
        int contiNum=0;
        for(int j=0;j<10;j++)
        {
            if(jariArr[j]==6)
            {
                contiNum++;
                if(contiNum==3)
                {
                    count++;
                    break;
                }
                continue;
            }
            contiNum=0;
        }
        if(count==n)
        {
            std::cout<<result<<std::endl;
            break;
        }
    }
    return 0;
}