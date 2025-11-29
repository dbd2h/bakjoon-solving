#include <iostream>
#include <string>
#include <vector>

using namespace std;

string sumF(string &s1, string &s2)
{
    string s;
    if(s1=="0" && s2=="0")
    {
        return "0";
    }
    int idx1=s1.size()-1;
    int idx2=s2.size()-1;
    bool isUp=0;
    while(idx1>-1 || idx2>-1)
    {
        int num1=0;
        if(idx1>-1)
        {
            num1=s1[idx1]-'0';
            idx1--;
        } 
        int num2=0;
        if(idx2>-1)
        {
            num2=s2[idx2]-'0';
            idx2--;
        }
        int sumV=num1+num2;
        if(isUp) sumV+=1;
        if(sumV/10==1)
        {
            isUp=1;
            sumV-=10;
        }
        else isUp=0;
        s=to_string(sumV)+s;
    }
    if(isUp) s="1"+s;
    return s;
}

int main()
{
    string dp[10001];
    dp[3]="4";
    dp[4]="7";
    for(int i=5;i<=10000;i++)
    {
        dp[i]=sumF(dp[i-1],dp[i-2]);
    }
    int num;
    while(cin>>num)
    {
        cout<<dp[num]<<"\n";
    }
}   