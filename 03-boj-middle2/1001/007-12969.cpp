#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    bool dp[31][31][15*29]={0}; // A,B,can make
    dp[0][0][0]=true;
    int countA=-1;
    int countB=-1;
    bool isFinish=false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i+j>=n) break;
            int countC=n-i-j-1;
            for(int x=0;x<n*(n-1)/2;x++)
            {
                if(!dp[i][j][x]) continue;
                dp[i+1][j][x]=true;
                if(countC*(i+j+1)+x==k)
                {
                    countA=i+1;
                    countB=j;
                    isFinish=true;
                    break;
                }
                dp[i][j+1][x+i]=true;
                if(countC*(i+j+1)+x+i==k)
                {
                    countA=i;
                    countB=j+1;
                    isFinish=true;
                    break;
                }
            }
            if(isFinish) break;
        }
        if(isFinish) break;
    }
    if(!isFinish)
    {
        cout<<-1;
        return 0;
    }
    int x=k-(n-countA-countB)*(countA+countB);
    string s;
    for(int i=countA+countB;i<n;i++)
    {
        s+='C';
    }
    while(countA+countB>0)
    {
        if(countA>0)
        {
            if(dp[countA-1][countB][x])
            {
                s='A'+s;
                countA--;
                continue;
            }
        }
        if(countB>0)
        {
            if(dp[countA][countB-1][x-countA])
            {
                s='B'+s;
                countB--;
                x-=countA;
                continue;
            }
        }
    }
    cout<<s;
}