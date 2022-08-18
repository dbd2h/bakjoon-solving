#include <iostream>

bool isHansoo(int number)
{
    int fnum=10,bnum=10,diff=10;
    while(number!=0)
    {
        if(bnum==10)
        {
            bnum=number%10;
        }
        else if(fnum==10)
        {
            fnum=number%10;
            diff=fnum-bnum;
        }
        else
        {
            bnum=fnum;
            fnum=number%10;
            if(diff!=fnum-bnum)
            {
                return false;
            }
            diff=fnum-bnum;
        }
        number/=10;
    }
    return true;
}

int main()
{
    int inputNum;
    std::cin>>inputNum;
    int count=0;

    for(int num=1;num<=inputNum;num++)
    {
        if(isHansoo(num))
        {
            count++;
        }
    }
    std::cout<<count<<"\n";
}

/*

1,2자리는 중요X but 얘네도 담을 수 있는 함수는 만들거, 

숫자 받고, 나누기 나머지로 배열 만들고, 자리 세기

*/