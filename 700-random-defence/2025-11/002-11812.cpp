#include <iostream>
typedef long long ll;

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k,q;
    cin>>n>>k>>q;
    for(int i=0;i<q;i++)
    {
        ll a,b;
        cin>>a>>b;
        if(k==1)
        {
            if(a<b) cout<<b-a<<"\n";
            else cout<<a-b<<"\n";
            continue;
        }
        int res=0;
        a-=2;
        b-=2;
        while(a!=b)
        {
            if(a>b)
            {
                a=a/k-1;
                res++;
            }
            else
            {
                b=b/k-1;
                res++;
            }
        }
        cout<<res<<"\n";
    }
}