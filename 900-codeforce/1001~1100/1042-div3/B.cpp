#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void program()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            if(i==n-1) cout<<-1;
            else cout<<-1<<" ";
        }
        else
        {
            if(i==n-1) cout<<2;
            else cout<<3<<" ";
        }
    }
    cout<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}