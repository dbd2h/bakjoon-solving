#include <iostream>
#include <string>
#include <map>
using namespace std;

string s;
long long res=1;
map<string,bool> m;

void changeS(int from, int to, int n)
{
    while(from!=to)
    {
        from++;
        from%=3;
        s[n-1]='A'+from;
        m[s]=1;
        cout<<s<<"\n";
        res++;
    }
}

void resMaker(int n, int c, string s)
{
    if(n==c)
    {
        if(!m[s]) cout<<s<<"\n";
        return;
    }   
    for(int i=0;i<3;i++)
    {
        if(c==0 && i==2) return;
        string next;
        if(i==0) next="A";
        else if(i==1) next="B";
        else if(i==2) next="C";
        next+=s;
        resMaker(n,c+1,next);
    }
}

void hanoi(int from, int to, int n)
{
    if(n==1)
    {
        changeS(from,to,n);
        return;
    }
    int diff=(to+3-from)%3;
    if(diff==2)
    {
        hanoi(from,to,n-1);
        changeS(from,3-from-to,n);
        hanoi(to,from,n-1);
        changeS(3-from-to,to,n);
        hanoi(from,to,n-1);
    }
    else if(diff==1)
    {
        hanoi(from,3-from-to,n-1);
        changeS(from,to,n);
        hanoi(3-from-to,to,n-1);
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) s+='A';
    cout<<s<<"\n";
    m[s]=1;
    hanoi(0,1,n);
    cout<<res<<"\n";
    //resMaker(n,0,"");
    
}
