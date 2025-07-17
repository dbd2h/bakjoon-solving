#include <iostream>
#include <string>

using namespace std;

int alpha[26]={0};
int str[50][26];
int alphaBystr[26][51]={0};
int isUnknown[50]={0};
int maxC=0;


void Excombination(int n, int k, int cur, int ex, int count)
{
    if(26-k==count)
    {
        if(maxC<n-ex)
        {
            maxC=n-ex;
        }
        return;
    }
    int curExStr[50]={0};
    int curEx=ex;
    for(int i=cur;i<26;i++)
    {
        if(alpha[i]==1)
        {
            continue;
        }
        if(count+k<i)
        {
            return;
        }
        for(int j=1;j<=alphaBystr[i][0];j++)
        {
            if(isUnknown[alphaBystr[i][j]]==1)
            {
                continue;
            }
            curExStr[curEx-ex]=alphaBystr[i][j];
            curEx++;
            isUnknown[alphaBystr[i][j]]=1;
        }
        Excombination(n, k, i+1, curEx, count+1);
        for(int j=0;j<curEx-ex;j++)
        {
            isUnknown[curExStr[j]]=0;
            curExStr[j]=0;
        }
        curEx=ex;
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    if(k<5)
    {
        string s;
        for(int i=0;i<n;i++)
        {
            cin>>s;
        }
        cout<<0;
        return 0;
    }
    alpha['a'-'a']=1;
    alpha['n'-'a']=1;
    alpha['t'-'a']=1;
    alpha['c'-'a']=1;
    alpha['i'-'a']=1;
    for(int i=0;i<n;i++)
    {
        string s;
        int c=0;
        cin>>s;
        int len=s.length();
        for(int j=4;j<len-4;j++)
        {
            if(alpha[s[j]-'a']==1)
            {
                continue;
            }
            str[i][s[j]-'a']=1;
        }
    }
    for(int i=0;i<26;i++)
    {
        if(alpha[i]==1)
        {
            continue;
        }
        for(int j=0;j<n;j++)
        {
            if(str[j][i]==1)
            {
                alphaBystr[i][0]++;
                alphaBystr[i][alphaBystr[i][0]]=j;
            }
        }
    }
    //alphaCheck(n,k,0,5,0);
    Excombination(n,k,0,0,0);
    cout<<maxC;
}