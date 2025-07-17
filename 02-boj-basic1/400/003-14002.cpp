#include <iostream>

using namespace std;

int main()
{
    int len;
    cin>>len;
    int arr[len];
    int seqArr[len][len]={0};
    for(int i=0;i<len;i++)
    {
        cin>>arr[i];
    }
    int lenArr[len];
    int fMax=0;
    int fMaxI=0;
    for(int i=0;i<len;i++)
    {
        int max=0;
        int maxI=i;
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i])
            {
                if(max<lenArr[j])
                {
                    max=lenArr[j];
                    maxI=j;
                }
            }
        }
        if(fMax<max)
        {
            fMax=max;
            fMaxI=i;
        }
        lenArr[i]=max+1;
        for(int j=0;j<max;j++)
        {
            seqArr[i][j]=seqArr[maxI][j];
        }
        seqArr[i][max]=arr[i];
    }
    cout<<fMax+1<<"\n";
    for(int i=0;i<fMax+1;i++)
    {
        cout<<seqArr[fMaxI][i]<<" ";
    }
}