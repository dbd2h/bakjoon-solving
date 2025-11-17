#include <iostream>

using namespace std;

int main()
{
    int t,a,s,b;
    cin>>t>>a>>s>>b;
    int check[201]={0};
    int rem=1'000'000;
    for(int i=0;i<a;i++)
    {
        int num;
        cin>>num;
        check[num]++;
    }
    int dp[4001][201]={0};
    int res=0;
    int count[201]={0};
    int totArr[201]={0};
    int curTot=0;
    for(int i=1;i<=t;i++)
    {
        if(check[i]==0)
        {
            continue;
        } 
        curTot+=check[i];
        totArr[i]=curTot;
        count[i]=1;
        dp[1][i]=1;
        if(s==1) res++;
    }
    
    for(int i=1;i<a;i++)
    {
        int tot=0;
        for(int j=1;j<=t;j++)
        {
            if(check[j]==0) continue;
            if(totArr[j]+1<i) continue;
            count[j]+=tot;
            dp[i+1][j]=tot;
            tot=count[j];
            tot%=rem;
            int idx=i+1-check[j];
            if(idx>0)
            {
                count[j]-=dp[idx][j];
                count[j]+=rem;
                count[j]%=rem;
            }
            if(i+1>=s && i+1<=b)
            {
                res+=count[j];
                res%=rem;
            }
        }
    }
    cout<<res;
}