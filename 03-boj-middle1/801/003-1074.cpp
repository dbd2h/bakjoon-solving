#include <iostream>

using namespace std;

int pow(int num, int exp)
{
    int res=1;
    for(int i=0;i<exp;i++)
    {
        res*=num;
    }
    return res;
}

int z(int n, int r, int c, int x, int y)
{
    if(n<1)
    {
        return 0;
    }
    int st=pow(2,n-1);
    if(r<x+st)
    {
        if(c<y+st) return st*st*0 + z(n-1,r,c,x,y);
        else return st*st*1 + z(n-1,r,c,x,y+st);
    }
    else
    {
        if(c<y+st) return st*st*2 + z(n-1,r,c,x+st,y);
        else return st*st*3 + z(n-1,r,c,x+st,y+st);
    }
}

int main()
{
    int n;
    int r,c;
    cin>>n>>r>>c;
    cout<<z(n,r,c,0,0);


}