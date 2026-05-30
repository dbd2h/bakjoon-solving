#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int test=0;test<t;test++)
    {
        int n;
        cin>>n;
        int min=1001;
        int max=0;
        for(int i=0;i<n;i++)
        {
            int num;
            cin>>num;
            if(num>max) max=num;
            if(num<min) min=num;
        }
        cout<<(max-min)*(n-1)<<"\n";
    }
}