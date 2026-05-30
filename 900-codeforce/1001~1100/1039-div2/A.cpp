#include <iostream>

using namespace std;

void trashBag()
{
    int n,c;
    cin>>n>>c;
    int cArr[32]={0};
    for(int i=0;i<n;i++)
    {
        int trash;
        cin>>trash;
        int d=c/trash;
        int co=-1;
        while(d)
        {
            co++;
            d/=2;
        }
        if(co!=-1)
        {
            cArr[co]++;
        }
    }
    int coin=0;
    int result=n;
    for(int i=31;i>=0;i--)
    {
        coin+=cArr[i];
        if(coin==0) continue;
        coin--;
        result--;
        if(result==0) break;
    }
    cout<<result<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        trashBag();
    }
}