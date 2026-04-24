#include <iostream>

using namespace std;

int main()
{
    int arr[1000001]={0};
    bool check[1000001]={0};
    int n;
    cin>>n;
    int numArr[100000];
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        check[num]=1;
        numArr[i]=num;
    }
    for(int i=1;i<=1000000;i++)
    {
        if(check[i]==0) continue;
        int cur=i*2;
        while(cur<=1000000)
        {
            if(check[cur])
            {
                arr[cur]--;
                arr[i]++;
            }
            cur+=i;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[numArr[i]]<<" ";
    }
}