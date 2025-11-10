#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int mul=1;
    while(b/mul)
    {
        mul*=10;
    }
    cout<<a+b-c<<"\n";  
    cout<<a*mul+b-c;
}