#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 5001

using namespace std;

int sumA[LEN];
int sumB[LEN];

void program()
{
    string a,b;
    cin>>a>>b;
    sumA[0]=sumB[0]=0;
    int aLen=a.size();
    int bLen=b.size();
    for(int i=0;i<aLen;i++)
    {
        int cur=a[i]-'0';
        sumA[i+1]=(sumA[i]+cur)%10;
    }
    for(int i=0;i<bLen;i++)
    {
        int cur=b[i]-'0';
        sumB[i+1]=(sumB[i]+cur)%10;
    }
    if(sumA[aLen]!=sumB[bLen])
    {
        cout<<-1<<"\n";
        return;
    }
    int lcs[LEN][LEN];
    for(int i=0;i<=aLen;i++) lcs[i][0]=0;
    for(int i=0;i<=bLen;i++) lcs[0][i]=0;
    for(int i=1;i<=aLen;i++)
    {
        for(int j=1;j<=bLen;j++)
        {
            if(sumA[i]==sumB[j])
            {
                lcs[i][j]=lcs[i-1][j-1]+1;
            }
            else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
        }
    }
    cout<<lcs[aLen][bLen]<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}