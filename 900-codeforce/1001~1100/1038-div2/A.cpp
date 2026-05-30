#include <iostream>

using namespace std;

void greedyGrid()
{
    int n,m;
    cin>>n>>m;
    if(n==1 || m==1)
    {
        cout<<"NO\n";
        return;
    }
    else if(n==2 && m==2)
    {
        cout<<"NO\n";
        return;
    }
    else
    {
        cout<<"YES\n";
        return;
    }

}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        greedyGrid();
    }
}

