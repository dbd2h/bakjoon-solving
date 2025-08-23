#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int q;
    cin>>q;
    priority_queue<int ,vector<int>, greater<int>> pq;
    for(int i=0;i<q;i++)
    {
        int a;
        cin>>a;
        if(a==2)
        {
            cout<<pq.top()<<"\n";
            pq.pop();
        }
        else
        {
            int b;
            cin>>b;
            pq.push(b);
        }
        
    }
}