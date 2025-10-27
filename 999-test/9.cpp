#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    queue<int> &cq=q;
    cq.pop();
    cout<<q.size();
}