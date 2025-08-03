#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n=10;
    int w=20;
    char b[2000];
    cin>>b;
    char c[2000];
    for(int i=0;i<n;i++)
    {
        c[i]=b[i];
    }
    for(int i=0;i<w-n;i++)
    {
        string s=c+i;
        cout<<s<<" "<<s.size()<<"\n";
        c[n+i]=b[n+i];
    }
}