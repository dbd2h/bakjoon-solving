#include <iostream>
#include <map>
#include <string>

using namespace std;

void problem()
{
    int n;
    cin>>n;
    int count=0;
    map<string,int> m;
    int wearArr[31]={0};
    for(int i=0;i<n;i++)
    {
        string wear, s;
        cin>>wear>>s;
        if(m[s]==0)
        {
            count++;
            m[s]=count;
            wearArr[m[s]]++;
        }
        else
        {
            wearArr[m[s]]++;
        }
    }
    if(count==0)
    {
        cout<<0<<"\n";
        return;
    }
    long long res=1;
    for(int i=1;i<=count;i++)
    {
        res*=(long long)(wearArr[i]+1);
    }
    res-=1;
    cout<<res<<"\n";
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) problem();
}