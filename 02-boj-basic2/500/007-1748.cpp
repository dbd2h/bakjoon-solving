#include <iostream>

using namespace std;

int main()
{
    int tens=1;
    int count=0;
    int num;
    int i=1;
    cin>>num;

    while(num>=tens*10)
    {
        tens*=10;
        count+=(tens-tens/10)*i;
        i++;
    }
    count+=(num-tens+1)*i;
    cout<<count;
}