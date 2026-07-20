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
    bool isM=false;
    bool isR=true;
    int bef=s[n-1]-'A';
    if(bef==2)
    {
        cout<<"NO\n";
        return;
    } 
    if(bef==1) isR=false;
    for(int i=n-2;i>=0;i--)
    {
        int cur=s[i]-'A';
        if(cur==bef)
        {
            if(isM)
            {
                cout<<"NO\n";
                return;
            }
        }
        else if((cur-bef+3)%3==1)
        {
            if(isM)
            {
                isM=false;
                isR=true;
            }
            else if(isR)
            {
                isM=true;
            }
            else
            {
                isR=true;
            }
        }
        else if((cur-bef+3)%3==2)
        {
            if(isM)
            {
                isM=false;
                isR=false;
            }
            else if(!isR)
            {
                isM=true;
            }
            else
            {
                isR=false;
            }
        }
        bef=cur;
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