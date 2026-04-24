#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[401];

int main()
{   
    int n,p;
    cin>>n>>p;
    for(int i=0;i<p;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}