#include <iostream>

using namespace std;

void recurF(int arr[], int l, int r)
{
    int root=arr[l];
    int middle=l+1;
    for(;middle<=r;middle++)
    {
        if(root<arr[middle]) break;
    }
    if(l+1<middle)
    {
        recurF(arr,l+1,middle-1);
    }
    if(middle<=r)
    {
        recurF(arr,middle,r);
    }
    cout<<root<<"\n";
}

int main()
{
    int num;
    int arr[10000];
    int idx=0;
    while(cin>>num)
    {
        arr[idx]=num;
        idx++;
    }
    recurF(arr,0,idx-1);
}