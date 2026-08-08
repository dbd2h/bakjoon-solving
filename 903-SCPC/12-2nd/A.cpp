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

using namespace std;

int arr[2001];

void program()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    string res;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int idx=(j+i)%n;
            arr[j]=s[idx]-'0';
        }
        string cur;
        int dis=10-arr[0];
        for(int j=0;j<n;j++)
        {
            cur+=((arr[j]+dis)%10+'0');
        }
        if(res.size()==0 || res>cur) res=cur;
    }
    cout<<res<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<endl;
        program();
    }
}
