#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void program()
{
    int n;
    cin>>n;
    int inc=0;
    int dec=0;
    int arr1[10000]={0};
    int arr2[10000]={0};
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>arr2[i];
    }
    for(int i=0;i<n;i++)
    {
        int n1,n2;
        n1=arr1[i];
        n2=arr2[i];
        if(n1==n2) continue;
        else if(n1>n2)
        {
            dec+=(n1-n2);
        }
        else if(n1<n2)
        {
            inc+=(n2-n1);
        }
    }   
    cout<<dec+1<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}