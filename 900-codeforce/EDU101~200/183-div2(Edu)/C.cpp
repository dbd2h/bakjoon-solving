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
 
void program()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int findV=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a') findV++;
        else findV--;
    }
    map<int,int> m;
    int num=0;
    int res=n;
    if(findV==0) res=0;
    m[0]=-1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a') num++;
        else num--;
        m[num]=i;
        if(m.find(num-findV) != m.end())
        {
            if(res>i-m[num-findV]) res=i-m[num-findV];
        }
    }
    if(res==n) res=-1;
    cout<<res<<"\n";
}
 
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}