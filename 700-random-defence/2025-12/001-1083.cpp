#include <iostream>


using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int s;
    cin>>s;
    int idx=0;
    while(s>0 && idx<n)
    {
        int num=0;
        int maxN=arr[idx];
        int maxI=idx;
        for(int i=idx+1;i<n;i++)
        {
            num++;
            if(num>s) break;
            if(maxN<arr[i])
            {
                maxN=arr[i];
                maxI=i;
            }
        }
        s-=(maxI-idx);
        if(maxI!=idx)
        {
            while(maxI>idx)
            {
                arr[maxI]=arr[maxI-1];
                maxI--;
            }
            arr[idx]=maxN;
        }
        
        idx++;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}