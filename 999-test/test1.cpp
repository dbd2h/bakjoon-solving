#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s="asdf";
    int a=100;
    s+=to_string(a);
    cout<<s;
}