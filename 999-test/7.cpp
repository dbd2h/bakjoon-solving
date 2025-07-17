#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> a;
    a.push_back(1);
    a.push_back(2);
    deque<int> b;
    b=a;
    cout<<b.front()<<"\n";
    b.pop_back();
    cout<<a.back()<<" "<<b.back();
}