#include <iostream>

using namespace std;

void PileSuffling()
{
    int n;
    cin>>n;
    long long result=0;
    for(int i=0;i<n;i++)
    {
        long long a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a>c && b>d)
        {
            result+=(a+b-d);
        }
        else if(b>d)
        {
            result+=(a+b-d);
        }
        else if(a>c)
        {
            result+=(a-c);
        }
    }
    cout<<result<<"\n";

}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        PileSuffling();
    }
}

// 0이 많고 1이 많은경우, 0이 적고 1이 많은 경우, 0이 많고 1이 적은 경우, 0이 적고 1이 적은 경우 X