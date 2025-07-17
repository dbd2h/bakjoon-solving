#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,x;
        int bit[200001]={0};
        cin>>n>>x;
        for(int i=0;i<n;i++)
        {
            int num;
            cin>>num;
            if(num>200000) continue;
            bit[num]+=1;
        }
        int result;
        for(int j=0;j<200001;j++)
        {
            result=j;
            if(bit[j]>0) continue;
            int num=j;
            num-=x;
            while(num>=0)
            {
                if(bit[num]>1)
                {
                    bit[num]--;
                    break;
                }
                num-=x;
            }
            if(num<0) break;
        }
        cout<<result<<"\n";
    }
}