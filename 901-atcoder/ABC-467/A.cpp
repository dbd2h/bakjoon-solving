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

int cmp(lld a, lld b)
{
    if(a+1e-9>b && a-1e-9<b) return 0;
    else if(a>b) return 1;
    else return -1;
}

int main()
{
    lld h,w;
    cin>>h>>w;
    h/=100;
    lld bmi=w/h/h;
    int res=cmp(bmi,(long double)25);
    if(res==-1) cout<<"No";
    else cout<<"Yes";
}