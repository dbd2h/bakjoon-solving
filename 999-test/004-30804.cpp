#include <iostream>

using namespace std;

int fruit[200000]={0};

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>fruit[i];
    }
    int res=0;
    for(int i=1;i<=9;i++)
    {
        for(int j=i+1;j<=9;j++)
        {
            int len=0;
            for(int k=0;k<n;k++)
            {
                if(fruit[k]==i || fruit[k]==j)
                {
                    len++;
                }
                else
                {
                    if(res<len) res=len;
                    len=0;
                }
            }
            if(res<len) res=len;
        }
    }
    cout<<res;
}