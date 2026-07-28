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
#define LEN 30001

using namespace std;

bool isPrime[LEN];
int arr[5];
bool bit[5];

void Per(int len, int c, string &s, int *res)
{
    if(len==c)
    {
        bool isN[5]={0};
        for(int i=0;i<=len;i++)
        {
            if(i==len)
            {
                *res=len;
                break;
            }
            int cur=0;
            for(int j=0;j<len;j++)
            {
                if(isN[j]) continue;
                cur*=10;
                cur+=s[j]-'0';
            }
            if(!isPrime[cur])
            {
                *res=max(*res,i);
                break;
            }
            isN[arr[i]]=1;
        }
        return;
    }
    for(int i=0;i<len;i++)
    {
        if(bit[i]) continue;
        bit[i]=1;
        arr[c]=i;
        Per(len,c+1,s,res);
        bit[i]=0;
    }
}

void program()
{
    string a,b;
    cin>>a>>b;
    int resA=0;
    int resB=0;
    Per(a.size(),0,a,&resA);
    Per(b.size(),0,b,&resB);
    if(resA>resB) cout<<1<<"\n";
    else if(resA<resB) cout<<2<<"\n";
    else cout<<3<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<LEN;i++) isPrime[i]=1;
    isPrime[1]=0;
    for(int i=2;i<LEN;i++)
    {
        if(!isPrime[i]) continue;
        for(int j=i*2;j<LEN;j+=i) isPrime[j]=0;
    }
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<endl;
        program();
    }
}