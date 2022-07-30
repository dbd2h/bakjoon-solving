#include <iostream>

int main()
{
    using namespace std;

    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int count;
    cin>>count;
    for(int i=0;i<count;i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<a+b<<"\n";
    }
}