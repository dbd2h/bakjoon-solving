#include <iostream>
#include <cmath>
#include <algorithm>

typedef long double ld;

using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n==0)
    {
        cout<<0;
        return 0;
    }
    ld cutP= (ld)n*0.15;
    int cutC= (int)(cutP+0.50000000001);
    int levelArr[300000];
    int tot=n-cutC*2;
    for(int i=0;i<n;i++)
    {
        cin>>levelArr[i];
    }
    sort(levelArr,levelArr+n);
    int res=0;
    for(int i=cutC;i<n-cutC;i++)
    {
        res+=levelArr[i];
    }
    res=(int)((ld)res/(ld)tot+0.50000000001);
    cout<<res;
}