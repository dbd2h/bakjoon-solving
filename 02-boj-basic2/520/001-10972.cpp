#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int p[n]={0};
    int rightBig=-1;
    cin>>p[0];
    for(int i=1;i<n;i++)
    {
        cin>>p[i];
        if(p[i-1]<p[i])
        {
            rightBig=i-1;
        }
    }
    if(rightBig==-1)
    {
        cout<<-1;
    }
    else
    {
        
        int index=rightBig;
        int dif=10000;
        for(int i=rightBig+1;i<n;i++)
        {
            if(p[i]-p[rightBig]<0)
            {
                continue;
            }
            if(p[i]-p[rightBig]<dif)
            {
                dif=p[i]-p[rightBig];
                index=i;
            }
        }
        int c=p[rightBig];
        p[rightBig]=p[index];
        p[index]=c;
        for(int i=rightBig+1;i<n;i++)
        {
            int min=p[i];
            int minI=i;
            for(int j=i+1;j<n;j++)
            {
                if(p[j]<min)
                {
                    min=p[j];
                    minI=j;
                }
            }
            c=p[i];
            p[i]=min;
            p[minI]=c;
        }
        for(int i=0;i<n;i++)
        {
            cout<<p[i]<<" ";
        }
    }
}