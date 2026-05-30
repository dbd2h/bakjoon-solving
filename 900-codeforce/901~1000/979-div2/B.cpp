#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int test=0;test<t;test++)
    {
        int n;
        cin>>n;
        cout<<'1';
        for(int i=1;i<n;i++)
        {
            cout<<'0';
        }
        cout<<"\n";
    }
}