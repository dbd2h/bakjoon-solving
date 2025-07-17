#include <iostream>

int main()
{
    int month,day,total;
    total=0;
    std::cin>>month>>day;
    for(int i=1;i<=month;i++)
    {
        if(i==month)
        {
            total+=day;
        }
        else if((i<8&&i%2==1)||(i>=8&&i%2==0))
        {
            total+=31;
        }
        else if(i==2)
        {
            total+=28;
        }
        else
        {
            total+=30;
        }
    }
    if(total%7==1)
    {
        std::cout<<"MON"<<"\n";
    }
    else if(total%7==2)
    {
        std::cout<<"TUE"<<"\n";
    }
    else if(total%7==3)
    {
        std::cout<<"WED"<<"\n";
    }
    else if(total%7==4)
    {
        std::cout<<"THU"<<"\n";
    }
    else if(total%7==5)
    {
        std::cout<<"FRI"<<"\n";
    }
    else if(total%7==6)
    {
        std::cout<<"SAT"<<"\n";
    }
    else if(total%7==0)
    {
        std::cout<<"SUN"<<"\n";
    }
}