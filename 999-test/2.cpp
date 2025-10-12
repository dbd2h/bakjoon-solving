#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

ll MOD=1'000'003;

int main()
{
    int n,s,e,t;
    cin>>n>>s>>e>>t;
    ll graph[50][50]={0};
    ll res[50][50]={0};
    for(int i=0;i<n*5;i++)
    {
        if(i%5==0) continue;
        graph[i][i-1]=1;
    }
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<s.size();j++)
        {
            int cur=s[j]-'0';
            if(cur==0) continue;
            graph[i*5][j*5+cur-1]=1;
        }
    }
    for(int i=0;i<n*5;i++)
	{
		for(int j=0;j<n*5;j++)
		{
			res[i][j]=graph[i][j];
		}
	}
	for(int c=1;c<=t;c++)
	{
		ll resC[50][50];
		for(int i=0;i<n*5;i++)
		{
			for(int j=0;j<n*5;j++)
			{
				ll sum=0;
				for(int k=0;k<n*5;k++)
				{
					sum+=res[i][k]*graph[k][j];
				}
				resC[i][j]=sum;
				resC[i][j]%=MOD;
			}
		}
		for(int i=0;i<n*5;i++)
		{
			for(int j=0;j<n*5;j++)
			{
				res[i][j]=resC[i][j];
				cout<<res[i][j];
			}
			cout<<"\n";
		}
		cout<<"\n";
	}
}