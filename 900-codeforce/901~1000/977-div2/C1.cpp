#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int test=0;test<t;test++)
    {
        int n,m,q;
        cin>>n>>m>>q;
        int bit[200001]={0};
        queue<int> a;
        queue<int> b;
        for(int i=0;i<n;i++)
        {
            int num;
            cin>>num;
            a.push(num);
        }
        for(int i=0;i<m;i++)
        {
            int num;
            cin>>num;
            b.push(num);
        }
        while(!a.empty() && !b.empty())
        {
            int num;
            num=b.front();
            if(bit[num]==0 && a.front()!=num) break;
            else if(a.front()==num)
            {
                bit[a.front()]=1;
                a.pop();
            }
            b.pop();
        }
        if(a.empty() || b.empty()) cout<<"YA\n";
        else cout<<"TIDAK\n";
    }
}