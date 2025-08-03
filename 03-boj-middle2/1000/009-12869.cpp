#include <iostream>
#include <algorithm>


using namespace std;

bool compare(int n1, int n2)
{
    return n1>n2;
}

int damage[6][3]={{9,3,1},{9,1,3},{3,9,1},{3,1,9},{1,3,9},{1,9,3}};

int main()
{
    int n;
    cin>>n;
    int arr[3]={0};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n,compare);
    int res=0;
    bool dp[61][61][61]={0};
    dp[arr[0]][arr[1]][arr[2]]=true;
    while(!dp[0][0][0])
    {
        res++;
        for(int i=0;i<61;i++)
        {
            for(int j=0;j<61;j++)
            {
                for(int k=0;k<61;k++)
                {
                    if(!dp[i][j][k]) continue;
                    for(int d=0;d<6;d++)
                    {
                        int a=i-damage[d][0];
                        int b=j-damage[d][1];
                        int c=k-damage[d][2];
                        if(a<0) a=0;
                        if(b<0) b=0;
                        if(c<0) c=0;
                        dp[a][b][c]=true;
                    }
                }
            }
        }
    }
    cout<<res;

}
