#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n<3 || s.substr(n-3,3)!="tea") cout<<"No";
    else cout<<"Yes";
}