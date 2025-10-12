#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

void program()
{
    int a,b;
    cin>>a>>b;
    if(a==b)
    {
        cout<<0;
    }
    else if(a%b==0 || b%a==0)
    {
        cout<<1;
    }
    else cout<<2;
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