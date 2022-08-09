#include <iostream>

int main()
{
    long long a,b,v;
    std::cin>>a>>b>>v;
    int day=((v-a)%(a-b)==0)?((v-a)/(a-b)+1):((v-a)/(a-b)+2);
    std::cout<<day<<"\n";
}