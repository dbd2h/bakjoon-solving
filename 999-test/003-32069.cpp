#include <iostream>
#include <algorithm>

using namespace std;

long long lightArr[300000]={0};
long long streetLamp[300000]={0};

int main()
{
    long long l;
    int n,k;
    cin>>l>>n>>k;
    long long first,last;
    for(int i=0;i<n;i++)
    {
        cin>>streetLamp[i];
    }
    for(int i=0;i<n+1;i++)
    {
        if(i==0)
        {
            first=streetLamp[i];
            continue;
        }
        if(i==n)
        {
            last=l-streetLamp[i-1];
            break;
        }
        lightArr[i-1]=streetLamp[i]-streetLamp[i-1]-1;
    }
    sort(lightArr,lightArr+n-1);
    int count=0;
    int num=0;
    for(int i=0;i<n;i++)
    {
        cout<<0<<"\n";
        count++;
        if(count>=k)
        {
            return 0;
        }
    }
    num++;
    int index=0;
    while(1)
    {
        if(first>=num)
        {
            cout<<num<<"\n";
            count++;
        }
        if(count>=k)
        {
            return 0;
        }
        for(int i=index;i<n-1;i++)
        {
            if((lightArr[i]+1)/2<num)
            {
                index++;
                continue;
            }
            else if((lightArr[i]+1)/2==num && lightArr[i]%2==1)
            {
                cout<<num<<"\n";
                count++;
            }
            else
            {
                cout<<num<<"\n";
                count++;
                if(count>=k)
                {
                    return 0;
                }
                cout<<num<<"\n";
                count++;
            }
            if(count>=k)
            {
                return 0;
            }
        }
        if(last>=num)
        {
            cout<<num<<"\n";
            count++;
        }
        if(count>=k)
        {
            return 0;
        }
        num++;
    }
}