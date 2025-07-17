#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int maxNum=n/2 * (n-n/2);
    if(k>maxNum)
    {
        cout<<-1;
        return 0;
    }
    else if(k==0)
    {
        cout<<'B';
        for(int i=1;i<n;i++)
        {
            cout<<'A';
        }
        return 0;
    }
    int dis=maxNum-k;
    int behindA=dis/(n-n/2);
    int betA=dis%(n-n/2);
    for(int i=0;i<n/2-behindA-1;i++)
    {
        cout<<'A';
    }
    for(int i=0;i<betA;i++)
    {
        cout<<'B';
    }
    cout<<'A';
    for(int i=0;i<n-n/2-betA;i++)
    {
        cout<<'B';
    }
    for(int i=0;i<behindA;i++)
    {
        cout<<'A';
    }
}