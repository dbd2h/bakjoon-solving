#include <iostream>
#include <queue>

using namespace std;

void problem()
{
    int n,k;
    cin>>n>>k;
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        pq.push({num,i});
    }
    for(int i=0;i<n;i++)
    {
        
    }
}


int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        problem();   
    }
}