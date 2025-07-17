#include <iostream>

int mul(int n, int ind)
{
    if(ind==0)
    {
        return 1;
    }
    return n*mul(n,ind-1);
}

int main()
{
    std::string n;
    int b;
    std::cin>>n>>b;
    int result=0;
    for(int i=n.size()-1;i>=0;i--)
    {
        int num;
        if(n[i]-'9'<=0)
        {
            num=n[i]-'0';
        }
        else
        {
            num=n[i]-'A'+10;
        }
        result+=mul(b,n.size()-i-1)*num;
    }
    std::cout<<result<<"\n";
}