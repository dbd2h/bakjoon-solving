#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int result[100001]={0};
    int n;
    cin>>n;
    priority_queue<int, vector<int>, greater<int>> hpq;
    priority_queue<int> lpq;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        hpq.push(a);
        if(i>2)
        {
            hpq.push(lpq.top());
            lpq.pop();
            lpq.push(hpq.top());
            hpq.pop();

        }
        if(i>0 && i%2==0)
        {
            lpq.push(hpq.top());
            hpq.pop();
        }
        result[i]=hpq.top();
    }
    for(int i=0;i<n;i++)
    {
        cout<<result[i]<<"\n";
    }
}

// 10 1 3 5 0 -10 99 98 97 96 95