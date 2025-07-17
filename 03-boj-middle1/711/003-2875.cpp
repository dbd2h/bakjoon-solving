#include <iostream>

using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int team=0;
    while(true)
    {
        if(n<2 || m<1 || n+m-3<k) break;
        team++;
        n-=2;
        m-=1;
    }
    cout<<team;
}