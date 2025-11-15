#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

bool isVowel(char c)
{
    if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U') return true;
    else return false;
}

int main()
{
    string s;
    cin>>s;
    int len=s.size();
    ll dp[101][3][3][2]={0};
    dp[0][0][0][0]=1;
    for(int i=0;i<len;i++)
    {
        char next=s[i];
        for(int con=0;con<3;con++)
        {
            for(int vow=0;vow<3;vow++)
            {
                for(int isL=0;isL<2;isL++)
                {
                    if(dp[i][con][vow][isL]==0) continue;
                    if(next=='_')
                    {
                        //L
                        if(con!=2) dp[i+1][con+1][0][1]+=dp[i][con][vow][isL];
                        //consonant
                        if(con!=2) dp[i+1][con+1][0][isL]+=dp[i][con][vow][isL]*20;
                        //vowel
                        if(vow!=2) dp[i+1][0][vow+1][isL]+=dp[i][con][vow][isL]*5;
                    }
                    else if(next=='L')
                    {
                        if(con!=2) dp[i+1][con+1][0][1]+=dp[i][con][vow][isL];
                    }
                    else if(isVowel(next))
                    {
                        if(vow!=2) dp[i+1][0][vow+1][isL]+=dp[i][con][vow][isL];
                    }
                    else
                    {
                        if(con!=2) dp[i+1][con+1][0][isL]+=dp[i][con][vow][isL];
                    }
                }
            }
        }
    }
    ll res=0;
    for(int con=0;con<3;con++)
    {
        for(int vow=0;vow<3;vow++)
        {
            if(dp[len][con][vow][1]==0) continue;
            res+=dp[len][con][vow][1];
        }
    }
    cout<<res;
}