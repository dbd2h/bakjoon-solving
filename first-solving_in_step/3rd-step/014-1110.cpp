#include <iostream>

int main()
{
    int con, var;
    int count=0;
    std::cin>>con;
    var=con;
    while(var!=con||count==0)
    {
        int tens=var/10;
        int units=var%10;
        var=units*10+(tens+units)%10;
        count++;
    }
    std::cout<<count<<std::endl;
    return 0;
}