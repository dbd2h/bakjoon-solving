#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int count;
    std::cin>>count;
    for(int i=count;i>=1;i--)
    {
        std::cout<<i<<"\n";
    }
    return 0;
}