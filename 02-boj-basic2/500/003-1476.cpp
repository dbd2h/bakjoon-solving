#include <iostream>

using namespace std;

int main()
{
    int e,s,m;
    cin>>e>>s>>m;
    int e2=1,s2=1,m2=1, year=1;
    while(e2!=e || s2!=s || m2!=m)
    {
        e2 = e2>=15 ? 1 : e2+1;
        s2 = s2>=28 ? 1 : s2+1;
        m2 = m2>=19 ? 1 : m2+1;
        year++;
    }
    cout<<year;
}