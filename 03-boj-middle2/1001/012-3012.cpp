#include <iostream>
#include <string>


using namespace std;

long long checkPa(int l, int r, string s)
{
    if(s[l]=='?' && s[r]=='?') return 3;
    else if(s[l]=='?' && (s[r]==')' || s[r]=='}' || s[r]==']')) return 1;
    else if(s[r]=='?' && (s[l]=='(' || s[l]=='{' || s[l]=='[')) return 1;
    else if(s[l]=='(' && s[r]==')' || s[l]=='{' && s[r]=='}' || s[l]=='[' && s[r]==']') return 1;
    else return 0;
}

int main()
{
    long long MOD=100000;
    int n;
    cin>>n;
    string s;
    cin>>s;
    long long dp[200][200]={0};
    bool isUp=false;
    for(int i=1;i<n;i+=2)
    {
        for(int j=0;i+j<n;j++)
        {
            int l=j;
            int r=i+j;
            long long sumV=0;
            for(int k=l+1;k<=r-2;k+=2)
            {
                long long n1,n2;
                n1=0;
                n2=0;
                if(k-l==1)
                {
                    n1=dp[l][k];
                }
                else
                {
                    n1=checkPa(l,k,s);
                    n1*=dp[l+1][k-1];
                }
                n2=dp[k+1][r];
                sumV+=n1*n2;
                if(sumV>=MOD) isUp=true;
                sumV%=MOD;
            }
            long long next=checkPa(l,r,s);
            if(r-l==1)
            {
                dp[l][r]=next;
                continue;
            }
            sumV+=next*dp[l+1][r-1];
            if(sumV>=MOD) isUp=true;
            sumV%=MOD;
            dp[l][r]=sumV;
        }
    }
    
    long long res=dp[0][n-1];
    if(res==0) isUp=false;
    if(isUp)
    {
        if(res/10000>0)
        {
            cout<<res;
            return 0;
        }
        cout<<0;
        if(res/1000>0)
        {
            cout<<res;
            return 0;
        }
        cout<<0;
        if(res/100>0)
        {
            cout<<res;
            return 0;
        }
        cout<<0;
        if(res/10>0)
        {
            cout<<res;
            return 0;
        }
        cout<<0;
        cout<<res;
        return 0;
    }
    cout<<dp[0][n-1];
}