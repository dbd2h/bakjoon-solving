#include <iostream>

int main()
{
    int h,m,need;
    std::cin>>h>>m>>need;

    m+=need%60;
    if(m>=60)
    {
        m-=60;
        h+=1;
    }

    h+=need/60;
    if(h>=24)
    {
        h-=24;
    }

    std::cout<<h<<" "<<m<<std::endl;
    return 0;
}