#include <iostream>
#include <queue>

using namespace std;

int hanoi[20]={0};
int finish[20]={0};
queue<pair<int,int>> order;
int c=0;

void makeHanoi(int n, int t)
{
    if(n==0)
    {

        return;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(hanoi[i]!=t)
        {
            makeHanoi(i, 6-t-hanoi[i]);
            order.push({hanoi[i],t});
            c++;
            hanoi[i]=t;
        }
        
    }
}

int main()
{
	int n;
    cin>>n;
    for(int i=1;i<=3;i++)
    {
        int m;
        cin>>m;
        for(int j=0;j<m;j++)
        {
            int num;
            cin>>num;
            hanoi[num-1]=i;
        }
    }
    for(int i=1;i<=3;i++)
    {
        int m;
        cin>>m;
        for(int j=0;j<m;j++)
        {
            int num;
            cin>>num;
            finish[num-1]=i;
        }
    }

    for(int i=n-1;i>=0;i--)
    {
        if(hanoi[i]==finish[i]) continue;
        makeHanoi(i,6-finish[i]-hanoi[i]);
        order.push({hanoi[i],finish[i]});
        c++;
        hanoi[i]=finish[i];
    }
    cout<<c<<"\n";
    if(n>10) return 0;
    for(int i=0;i<c;i++)
    {
        cout<<order.front().first<<" "<<order.front().second<<"\n";
        order.pop();
    }
}