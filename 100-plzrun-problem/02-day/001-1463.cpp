#include <iostream>

int minPositive(int l, int r)
{
    if(l<=0)
    {
        return r;
    }
    else if(r<=0)
    {
        return l;
    }
    else if(l<r)
    {
        return l;
    }
    else
    {
        return r;
    }
}

int miniCount(int num, int minusCount, int total)
{
    if(num==1)
    {
        return total;
    }
    else if(minusCount==3)
    {
        return 0;
    }
    else
    {
        if(num%6==0)
        {
            return minPositive(minPositive(miniCount(num-1,minusCount+1,total+1),miniCount(num/2,0,total+1)),miniCount(num/3,0,total+1));
        }
        else if(num%2==0)
        {
            return minPositive(miniCount(num-1,minusCount+1,total+1),miniCount(num/2,0,total+1));
        }
        else if(num%3==0)
        {
            return minPositive(miniCount(num/3,0,total+1),miniCount(num-1,minusCount+1,total+1));
        }
        else
        {
            return miniCount(num-1,minusCount+1,total+1);
        }
    }
}

int main()
{
    int num,total;
    std::cin>>num;
    total=0;
    total=miniCount(num,0,0);
    std::cout<<total<<"\n";
    return 0;
}