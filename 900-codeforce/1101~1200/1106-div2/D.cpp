#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 1000001

using namespace std;

vector<int> primeV;

void program()
{
    int n;
    cin>>n;
    int res=0;
    int sumV=0;
    for(auto &p:primeV)
    {
        if(p*p>n) break;
        if(n%p!=0) continue;
        res++;
        while(n>1 && n%p==0)
        {
            n/=p;
            sumV++;
        }
    }
    if(n!=1)
    {
        res++;
        sumV++;
    }
    res+=(sumV-1);
    cout<<res<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    bool arr[LEN]={0};
    for(int i=2;i<LEN;i++)
    {
        if(arr[i]) continue;
        primeV.push_back(i);
        for(int j=2;j*i<LEN;j++)
        {
            arr[j*i]=1;
        }
    }
    for(int i=0;i<t;i++)
    {
        program();
    }
}