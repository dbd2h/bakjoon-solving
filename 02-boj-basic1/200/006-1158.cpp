#include <iostream>

using namespace std;

struct queue
{
    long long arr[5000*5000];
    int f;
    int b;

    void init()
    {
        f=0;
        b=-1;
    }

    void push(int x)
    {
        b++;
        arr[b]=x;
    }

    int pop()
    {
        if(f>b)
        {
            return -1;
        }
        f++;
        return arr[f-1];
    }

    int size()
    {
        return b-f+1;
    }

    int empty()
    {
        if(f>b)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int front()
    {
        if(f>b)
        {
            return -1;
        }
        return arr[f];
    }

    int back()
    {
        if(f>b)
        {
            return -1;
        }
        return arr[b];
    }
};

int main()
{
    queue q;
    q.init();
    int n,k;
    cin>>n>>k;
    int num;
    int final[n];
    for(int i=1;i<=n;i++)
    {
        q.push(i);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k-1;j++)
        {
            num=q.pop();
            q.push(num);
        }
        num=q.pop();
        final[i]=num;
    }
    cout<<'<';
    for(int i=0;i<n;i++)
    {
        cout<<final[i];
        if(i==n-1)
        {
            break;
        }
        cout<<", ";
    }
    cout<<">\n";
}