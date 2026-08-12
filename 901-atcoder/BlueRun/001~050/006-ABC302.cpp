#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 200001

using namespace std;

int dp[5][5]={0};

int main()
{
    int n;
    cin>>n;
    int arr[LEN];
    int sortArr[LEN];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sortArr[i]=arr[i];
    } 
    sort(sortArr,sortArr+n);
    for(int i=0;i<n;i++)
    {
        int a=sortArr[i];
        int b=arr[i];
        if(a==b) continue;
        dp[b][a]++;
    }
    int res=0;
    for(int i=1;i<=4;i++)
    {
        for(int j=i+1;j<=4;j++)
        {
            int num=min(dp[i][j],dp[j][i]);
            dp[i][j]-=num;
            dp[j][i]-=num;
            res+=num;
        }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=i+1;j<=4;j++)
        {
            for(int k=j+1;k<=4;k++)
            {
                int num=min(dp[i][j],dp[j][k]);
                num=min(num,dp[k][i]);
                res+=num*2;
                dp[i][j]-=num;
                dp[j][k]-=num;
                dp[k][i]-=num;
                num=min(dp[i][k],dp[k][j]);
                num=min(num,dp[j][i]);
                res+=num*2;
                dp[i][k]-=num;
                dp[k][j]-=num;
                dp[j][i]-=num;
            }
        }
    }
    int num=0;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++) num+=dp[i][j];
    }
    res+=(num/4)*3;
    cout<<res;
}

// time: 31M 59S Solve
// 1. 신호: n의 개수가 4까지 뿐이고, 각 숫자끼리 바꿀 때 횟수를 최소화 하기위한 바꾸는 과정이 한정적임.
// 2. 도구: 주어진 배열과 정렬된 배열을 비교하여, 각 숫자가 어떤 숫자와 바껴야 하는지 개수를 기록하고, 가장 효율적인 방법의 개수부터 찾는다.
// 3. 막힌 지점: 2개를 바꿨을 때 3개 바꿀거가 4개 바꾸게 되어서 더 비효율적으로 되지 않을까란 생각을 했고, 3개 바꾸는 과정에서 바꾸는 방향의 우선순위가 있지 않을까란 생각을 함.
// 근데 이들을 증명하는게 어려웠음.