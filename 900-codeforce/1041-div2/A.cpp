#include <iostream>

using namespace std;

void problem()
{
    int n;
    cin>>n;
    int arr[100]={0};
    int first=-1;
    bool isFail=false;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(first==-1)
        {
            first=arr[i];
        }
        else if(arr[i]!=-1 && first!=arr[i])
        {
            isFail=true;
        }
        if(arr[i]==0)
        {
            isFail=true;
        }
    }
    if(isFail) cout<<"NO\n";
    else cout<<"YES\n";
    
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        problem();
    }   
}