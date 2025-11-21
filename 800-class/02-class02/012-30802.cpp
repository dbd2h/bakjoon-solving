#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[6];
    for(int i=0;i<6;i++)
    {
        cin>>arr[i];
    }
    int t,p;
    cin>>t>>p;
    int tshirtRes=0;
    for(int i=0;i<6;i++)
    {
        tshirtRes+=((arr[i]+t-1)/t);
    }
    cout<<tshirtRes<<"\n";
    cout<<n/p<<" "<<n%p;
}