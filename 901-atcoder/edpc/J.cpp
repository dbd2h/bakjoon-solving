#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

using namespace std;

lld dp[301][301][301]={0};

void solve(int a, int b, int c, int n)
{
    lld res=(lld)n;
    if(a>0)
    {
        if(dp[a-1][b][c]==0 && !(a==1 && b==0 && c==0)) solve(a-1,b,c,n);
        res+=(lld)a*dp[a-1][b][c];
    } 
    if(b>0)
    {
        if(dp[a+1][b-1][c]==0) solve(a+1,b-1,c,n);
        res+=(lld)b*dp[a+1][b-1][c];
    } 
    if(c>0)
    {
        if(dp[a][b+1][c-1]==0) solve(a,b+1,c-1,n);
        res+=(lld)c*dp[a][b+1][c-1];
    } 
    res/=(lld)(a+b+c);
    dp[a][b][c]=res;
}

int main()
{
    cout<<fixed;
    cout.precision(13);
    int n;
    cin>>n;
    int a,b,c;
    a=b=c=0;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        if(num==1) a++;
        else if(num==2) b++;
        else if(num==3) c++;
    }
    solve(a,b,c,n);
    cout<<dp[a][b][c];
}

// 1. dp[a][b][c]: N개 중에 1개짜리 a개, 2개짜리 b개, 3개짜리 c개 있을 때 이들을 다 먹을 기대값
// 2. 전이: dp[a][b][c]=1+(a/N)xdp[a-1][b][c]+(b/N)xdp[a+1][b-1][c]+(c/N)xdp[a][b+1][c-1]+((N-a-b-c)/N)xdp[a][b][c]
// 위 식을 정리하면 dp[a][b][c]=(1/(a+b+c))x(N + a x dp[a-1][b][c] + b x dp[a+1][b-1][c] + c x dp[a][b+1][c-1])
// 3. 초기값/답: dp[0][0][0]=0 / 답: 문제에 적힌 1,2,3 접시 개수를 각각 a,b,c라 하면 dp[a][b][c]