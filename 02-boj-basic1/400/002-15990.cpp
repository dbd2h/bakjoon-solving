#include <iostream>
#define div 1'000'000'009

using namespace std;

int main()
{
    int c;
    cin>>c;
    long long arr[100001]={1};
    int result[c]={0};
    int max=-1;
    long long p1=1, p2_0=1, p2_1=1, p3_0=1, p3_1=1, p3_2=1;
    for(int i=0;i<c;i++)
    {
        cin>>result[i];
        if(result[i]>max)
            max=result[i];
    }
    for(int i=1;i<=max;i++)
    {
        arr[i]+=p1;
        if(i==1)
        {
            p1=arr[i]-p1;
            continue;
        }
        if(i%2==0)
        {
            arr[i]+=p2_0;
        }
        else if(i%2==1)
        {
            arr[i]+=p2_1;
        }
        if(i==2)
        {
            p1=arr[i]-p1;
            p2_0=arr[i]-p2_0;
            continue;
        }
        if(i%3==0)
        {
            arr[i]+=p3_0;
            p3_0=arr[i]-p3_0;
            while(p3_0<0)
                p3_0+=div;
        }
        else if(i%3==1)
        {
            arr[i]+=p3_1;
            p3_1=arr[i]-p3_1;
            while(p3_1<0)
                p3_1+=div;
        }
        else if(i%3==2)
        {
            arr[i]+=p3_2;
            p3_2=arr[i]-p3_2;
            while(p3_2<0)
                p3_2+=div;
        }

        arr[i]%=div;
        while(arr[i]<0)
                arr[i]+=div;

        p1=arr[i]-p1;
        while(p1<0)
            p1+=div;
        if(i%2==0)
        {
            p2_0=arr[i]-p2_0;
            while(p2_0<0)
                p2_0+=div;
        }
        else if(i%2==1)
        {
            p2_1=arr[i]-p2_1;
            while(p2_1<0)
                p2_1+=div;
        }
        

    }
    for(int i=0;i<c;i++)
    {
        cout<<arr[result[i]]<<"\n";
    }
}