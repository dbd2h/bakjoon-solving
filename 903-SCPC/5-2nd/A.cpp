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

void program()
{
    string a,b;
    cin>>a>>b;
    
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