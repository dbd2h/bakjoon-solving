#include <iostream>
#include <vector>

long long sum(std::vector<int> &a){
    int sum=0;
    std::cout<<sizeof(a)<<std::endl;
    for(int i=0;i<std::size(a);i++)
    {
        std::cout<<a[i]<<"\n";
        sum+=a[i];
    }
    return sum;
}

int main()
{
    std::vector<int> v(5,2);
    std::cout<<sum(v)<<std::endl;
}