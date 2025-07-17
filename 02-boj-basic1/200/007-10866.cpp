#include <iostream>
#include <string>

#define MAX 10'000

using namespace std;

struct Deque{
    int arr[MAX];
    int f;
    int b;

    void init()
    {
        f=0;
        b=1;
    }
    void push_front(int x)
    {
        arr[f]=x;
        f=(f+MAX-1)%MAX;
    }
    void push_back(int x)
    {
        arr[b]=x;
        b=(b+1)%MAX;
    }
    int pop_front()
    {
        if((b-f+MAX)%MAX==1)
        {
            return -1;
        }
        f=(f+1)%MAX;
        int out=arr[f];
        return out;
    }
    int pop_back()
    {
        if((b-f+MAX)%MAX==1)
        {
            return -1;
        }
        b=(b+MAX-1)%MAX;
        int out=arr[b];
        return out;
    }
    int size()
    {
        return (b-f+MAX-1)%MAX;
    }
    int empty()
    {
        if((b-f+MAX)%MAX==1)
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
        if((b-f+MAX)%MAX==1)
        {
            return -1;
        }
        return arr[(f+1)%MAX];
    }
    int back()
    {
        if((b-f+MAX)%MAX==1)
        {
            return -1;
        }
        return arr[(b-1+MAX)%MAX];
    }
};

int main()
{
    Deque deque;
    deque.init();
    int count;
    cin>>count;
    string s;
    for(int i=0;i<count;i++)
    {
        cin>>s;
        if(s=="push_front")
        {
            int num;
            cin>>num;
            deque.push_front(num);
        }
        else if(s=="push_back")
        {
            int num;
            cin>>num;
            deque.push_back(num);
        }
        else if(s=="pop_front")
        {
            cout<<deque.pop_front()<<"\n";
        }
        else if(s=="pop_back")
        {
            cout<<deque.pop_back()<<"\n";
        }
        else if(s=="size")
        {
            cout<<deque.size()<<"\n";
        }
        else if(s=="empty")
        {
            cout<<deque.empty()<<"\n";
        }
        else if(s=="front")
        {
            cout<<deque.front()<<"\n";
        }
        else if(s=="back")
        {
            cout<<deque.back()<<"\n";
        }
    }
}