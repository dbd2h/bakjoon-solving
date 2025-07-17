#include <iostream>
#define div 9901

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n+1][3]={0};
    arr[1][0]=arr[1][1]=arr[1][2]=1;
    for(int i=2;i<=n;i++)
    {
        arr[i][0]=(arr[i-1][1]+arr[i-1][2])%div;
        arr[i][1]=(arr[i-1][0]+arr[i-1][2])%div;
        arr[i][2]=(arr[i-1][0]+arr[i-1][1]+arr[i-1][2])%div;
    }
    cout<<(arr[n][0]+arr[n][1]+arr[n][2])%div;
}