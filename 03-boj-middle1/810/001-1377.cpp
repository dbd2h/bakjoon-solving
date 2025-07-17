#include <iostream>
#include <algorithm>

using namespace std;

int bit[1000001]={0};

int main()
{
    int N;
    cin>>N;
    int A[500001]={0};
    int s_arr[500001]={0};
    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
        s_arr[i]=A[i];
    }
    sort(s_arr+1, s_arr+N+1);
    for(int i=1;i<=N;i++)
    {
        bit[s_arr[i]]=i;
    }
    int maxV=0;
    for(int i=1;i<=N;i++)
    {
        int num=i-bit[A[i]]+1;
        if(num>maxV) maxV=num;
    }
    cout<<maxV;
}