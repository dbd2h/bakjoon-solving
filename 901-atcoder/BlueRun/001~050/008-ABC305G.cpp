#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define MOD (ll)998244353

using namespace std;
    vector<string> inputV;
    vector<string> v(64);

void vMaker(ll len, int cur, string s, int num)
{
    if(len==cur)
    {
        v[num]=s;
        return;
    }
    vMaker(len,cur+1,s+'a',num*2);
    vMaker(len,cur+1,s+'b',num*2+1);
}

void mulMat(ll m1[33][33], ll m2[33][33], int len)
{
    ll cM[33][33];
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            ll cur=0;
            for(int k=0;k<len;k++)
            {
                cur+=m1[i][k]*m2[k][j];
                cur%=MOD;
            }
            cM[i][j]=cur;
        }
    }
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++) m1[i][j]=cM[i][j];
    }
}

int main()
{
    ll n,m;
    cin>>n>>m;

    int len=0;
    for(int i=0;i<m;i++)
    {
        string s;
        cin>>s;
        if(len<s.size()) len=s.size();
        inputV.push_back(s);
    }
    if(n<=len)
    {
        vMaker(n,0,"",0);
        ll res=0;
        int p=1;
        for(int i=0;i<n;i++)p*=2;
        for(int i=0;i<p;i++)
        {
            string s=v[i];
            bool isT=true;
            for(int j=0;j<m;j++)
            {
                if(s.find(inputV[j])!=string::npos)
                {
                    isT=false;
                    break;
                }
            }
            if(isT) res++;
        }
        cout<<res;
        return 0;
    }
    vMaker((ll)len-1,0,"",0);
    int p=1;
    for(int i=0;i<len-1;i++) p*=2;
    ll mat[33][33]={0};
    
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<p;j++)
        {
            string cur1=v[i][0]+v[j];
            string cur2=v[i]+v[j][len-2];
            if(cur1!=cur2) continue;
            bool isT=true;
            for(int k=0;k<m;k++)
            {
                if(cur1.find(inputV[k])!=string::npos)
                {
                    isT=false;
                    break;
                }
            }
            if(!isT) continue;
            mat[i][j]=1;
        }
    }
    ll tot=n-len+1;
    ll resM[33][33]={0};
    for(int i=0;i<p;i++) resM[i][i]=1;

    while(tot)
    {
        if(tot%2==1) mulMat(resM,mat,p);
        mulMat(mat,mat,p);
        tot/=2; 
    }
    ll res=0;
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<p;j++)
        {
            res+=resM[i][j];
            res%=MOD;
        }
    }
    cout<<res;
} 