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

void program()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int from=0;
    int to=1;
    for(int i=n-1;i>=0;i--)
    {
        int via=3-from-to;
        int cur=s[i]-'A';
        int diff=(to-from+3)%3;
        if(diff==1)
        {
            if(via==cur)
            {
                cout<<"NO\n";
                return;
            }
            else if(from==cur) to=via;
            else if(to==cur) from=via;
        }
        else if(diff==2)
        {
            if(via==cur)
            {
                int c=from;
                from=to;
                to=c;
            }
        }
    }
    cout<<"YES\n";
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