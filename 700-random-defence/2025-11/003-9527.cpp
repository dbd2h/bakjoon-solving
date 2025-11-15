#include <iostream>

typedef long long ll;

using namespace std;

ll fullCounter(ll two, int bitC)
{
    if(bitC==1) return 1;
    return two+two*(ll)(bitC-1)/2;
}

ll subCounter(ll two, ll last, int bitC)
{
    ll bit=1;
    ll res=0;
    ll lastCount=1;
    for(int i=0;i<bitC;i++)
    {
        if(last!=two)
        {
            res+=(last-two)/2*bit;
            if(last%2==1)
            {
                res+=lastCount;
                lastCount+=bit;
            }
            two/=2;
            last/=2;
            if(two!=last) bit*=2;
            else bit+=lastCount;
        }
        else
        {
            if(two%2==1) res+=lastCount;
            last/=2;
            two/=2;
        }
    }
    return res;
}

int main()
{
    ll a,b;
    cin>>a>>b;
    ll two=1;
    int bitC=1;
    ll res=0;
    while(true)
    {
        if(a>two && a<two*2)
        {
            if(b<two*2-1 && b>=two)
            {
                res+=subCounter(two,b,bitC);
                res-=subCounter(two,a-1,bitC);
                break;
            }
            res+=fullCounter(two,bitC);
            res-=subCounter(two,a-1,bitC);
        }   
        else if(a<=two && two*2-1<=b)
        {
            res+=fullCounter(two,bitC);
        }
        else if(b<two*2-1 && b>=two)
        {
            res+=subCounter(two,b,bitC);
        }
        else if(b<two)
        {
            break;
        }
        two*=2;
        bitC++;
    }
    cout<<res;
}