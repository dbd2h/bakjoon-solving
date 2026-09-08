#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
typedef long long ll;
typedef long double lld;
#define LEN 300001
#define INF (1e9+7)

using namespace std;

int arr[LEN];
int sumArr[4][LEN];

int order[4][4]={{0,0,1,1},{0,1,1,0},{1,1,0,0},{1,0,0,1}};

void program()
{
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++) arr[i]=s[i-1]-'0';
    sumArr[0][0]=sumArr[1][0]=sumArr[2][0]=sumArr[3][0]=0;
    int sumV=0;
    int idx=1;
    for(int i=0;i<4;i++)
    {
        idx=1;
        sumV=0;
        while(idx<=n)
        {
            sumV+=4;
            for(int j=0;j<4;j++)
            {
                if(arr[idx]==order[i][j])
                {
                    sumArr[i][idx]=sumV-idx;
                    idx++;
                }
                if(idx>n) break;
            }
        }
    }
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        int res=INF;
        for(int j=0;j<4;j++)
        {
            
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t=1;
    for(int i=0;i<t;i++)
    {
        program();
    }
}