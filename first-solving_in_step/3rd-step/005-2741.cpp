#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int number;
    std::cin>>number;
    for(int i=1;i<=number;i++)
    {
        std::cout<<i<<"\n";
    }
    return 0;
}