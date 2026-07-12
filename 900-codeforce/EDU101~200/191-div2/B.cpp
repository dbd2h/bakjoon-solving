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

void program()
{
    int n;
	cin>>n;
	if (n%2==0)
    {
        for (int i=0; i<n; i+=2)
		{
			cout<<i+2<<" "<<i+1<<" "<<i+1<<" "<<i+2<<" ";
			cout<<i+1<<" "<<i+2<<" "<<i+2<<" "<<i+1<<" ";
		}
	}
	else
	{
		cout<<"1 1 2 1 2 3 1 3 2 2 3 3 ";
		for (int i=3; i<n; i+=2)
		{
			cout<<i+2<<" "<<i+1<<" "<<i+1<<" "<<i+2<<" ";
			cout<<i+1<<" "<<i+2<<" "<<i+2<<" "<<i+1<<" ";
		}
	}
	cout<<"\n";
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