#include <iostream>

using namespace std;

void leftmostBelow()
{
    int n;
    cin>>n;
    int minV=1000000000;
    bool isend=false;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        if(num<minV) minV=num;
        else if(num>=minV*2)
        {
            isend=true;
        }
    }
    if(isend)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        leftmostBelow();
    }
}