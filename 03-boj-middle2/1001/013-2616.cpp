#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int passenger[50001]={0};
    int c=0;
    int sumV=0;
    for(int i=1;i<=n;i++)
    {
        cin>>passenger[i];
    }
    int s;
    cin>>s;
    int sumArr[50001]={0};
    for(int i=1;i<=n;i++)
    {
        c++;
        sumV+=passenger[i];
        if(c<s) continue;
        sumArr[i]=sumV;
        sumV-=passenger[i-s+1];
    }
    int dp1[50001]={0};
    int dp2[50001][2]={0};
    int dp3[50001][3]={0};
    for(int i=s;i<=n;i++)
    {
        if(i==s)
        {
            dp1[i]=s;
            continue;
        }
        int n1=sumArr[i];
        int n2=sumArr[dp1[i-1]];
        if(n1>n2) dp1[i]=i;
        else dp1[i]=dp1[i-1];
    }
    for(int i=s*2;i<=n;i++)
    {
        if(i==s*2)
        {
            dp2[i][0]=s;
            dp2[i][1]=s*2;
            continue;
        }
        int n1=sumArr[dp1[i-s]]+sumArr[i];
        int n2=sumArr[dp2[i-1][0]]+sumArr[dp2[i-1][1]];
        if(n1>n2)
        {
            dp2[i][0]=dp1[i-s];
            dp2[i][1]=i;
        }
        else
        {
            dp2[i][0]=dp2[i-1][0];
            dp2[i][1]=dp2[i-1][1];
        }
    }
    for(int i=s*3;i<=n;i++)
    {
        if(i==s*3)
        {
            dp3[i][0]=s;
            dp3[i][1]=s*2;
            dp3[i][2]=s*3;
            continue;
        }
        int n1=sumArr[dp2[i-s][0]]+sumArr[dp2[i-s][1]]+sumArr[i];
        int n2=sumArr[dp3[i-1][0]]+sumArr[dp3[i-1][1]]+sumArr[dp3[i-1][2]];
        if(n1>n2)
        {
            dp3[i][0]=dp2[i-s][0];
            dp3[i][1]=dp2[i-s][1];
            dp3[i][2]=i;
        }
        else
        {
            dp3[i][0]=dp3[i-1][0];
            dp3[i][1]=dp3[i-1][1];
            dp3[i][2]=dp3[i-1][2];
        }
    }
    cout<<sumArr[dp3[n][0]]+sumArr[dp3[n][1]]+sumArr[dp3[n][2]];
}