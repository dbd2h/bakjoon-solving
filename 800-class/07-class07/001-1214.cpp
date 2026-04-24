#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    int d,p,q;
    cin>>d>>p>>q;
    if(p<q)
    {
        int c=p;
        p=q;
        q=c;
    }
    int idx=(d-1)/p+1;
    int res=p*idx;
    int gcdV=gcd(p,q);
    int fromV=idx-q/gcdV;
    if(fromV<0) fromV=0;
    idx-=1;
    
    for(idx;idx>=fromV;idx--)
    {
        int rem=d-p*idx;
        if(rem%q==0)
        {
            res=d;
            break;
        }
        int curDiv=(rem-1)/q+1;
        int cur=p*idx+q*curDiv;
        if(res>cur) res=cur;
    }
    cout<<res;
}