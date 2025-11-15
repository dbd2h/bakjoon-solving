#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int res=0;
    for(int i=a;i<=b;i++)
    {
        int idx=i;
        while(idx)
        {
            if(idx%2==1) res++;
            idx/=2;
        }
    }
    cout<<res;
}