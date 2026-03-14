#include <iostream>
#include <queue>

using namespace std;

void problem()
{
    int k;
    cin>>k;
    priority_queue<int> highPq;
    priority_queue<int, vector<int>, greater<int>> lowPq;
    priority_queue<int> lowPqDel;
    priority_queue<int, vector<int>, greater<int>> highPqDel;
    for(int i=0;i<k;i++)
    {
        char s;
        int num;
        cin>>s>>num;
        if(s=='I')
        {
            highPq.push(num);
            lowPq.push(num);
            continue;
        }
        if(num==1)
        {
            while(!highPq.empty() && !lowPqDel.empty() && highPq.top()==lowPqDel.top())
            {
                highPq.pop();
                lowPqDel.pop();
            }
            if(highPq.empty()) continue;
            int delNum=highPq.top();
            highPq.pop();
            highPqDel.push(delNum);
        }
        else if(num==-1)
        {
            while(!lowPq.empty() && !highPqDel.empty() && lowPq.top()==highPqDel.top())
            {
                lowPq.pop();
                highPqDel.pop();
            }
            if(lowPq.empty()) continue;
            int delNum=lowPq.top();
            lowPq.pop();
            lowPqDel.push(delNum);
        }
    }
    while(!highPq.empty() && !lowPqDel.empty() && highPq.top()==lowPqDel.top())
    {
        highPq.pop();
        lowPqDel.pop();
    }
    while(!lowPq.empty() && !highPqDel.empty() && lowPq.top()==highPqDel.top())
    {
        lowPq.pop();
        highPqDel.pop();
    }
    if(highPq.empty())
    {
        cout<<"EMPTY\n";
    }
    else
    {
        cout<<highPq.top()<<" "<<lowPq.top()<<"\n";
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++) problem();
}