#include <iostream>
#include <map>

using namespace std;

int main()
{
    int t;
    cin>>t;
    int n,m;
    int arr1[1000]={0};
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    int arr2[1000]={0};
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }
    map<long long, int> numTot;
    for(int i=0;i<n;i++)
    {
        long long tot=0;
        for(int j=i;j<n;j++)
        {
            tot+=arr1[j];
            numTot[tot]++;
        }
    }
    long long res=0;
    for(int i=0;i<m;i++)
    {
        long long tot=0;
        for(int j=i;j<m;j++)
        {
            tot+=arr2[j];
            res+=numTot[t-tot];
        }
    }
    cout<<res;
}