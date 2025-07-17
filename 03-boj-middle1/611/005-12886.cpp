#include <iostream>
#include <queue>

using namespace std;

int leftLarger(int a, int b)
{
    if(a>b)
    {
        return 1;
    }
    else if(a<b)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int a,b,c;
    cin>>a>>b>>c;


    int count=0;
    queue<int> qa;
    queue<int> qb;
    queue<int> qc;
    queue<int> qCount;
    qa.push(a);
    qb.push(b);
    qc.push(c);
    qCount.push(count);
    while(!qa.empty())
    {
        a=qa.front();
        b=qb.front();
        c=qc.front();
        count=qCount.front();
        if(count==10)
        {
            cout<<0;
            return 0;
        }
        if(a==b && b==c)
        {
            cout<<1;
            return 0;
        }
        qa.pop();
        qb.pop();
        qc.pop();
        qCount.pop();
        if(leftLarger(a,b)==1)
        {
            qa.push(a-b);
            qb.push(b+b);
            qc.push(c);
            qCount.push(count+1);
        }
        else if(leftLarger(a,b)==0)
        {
            qa.push(a+a);
            qb.push(b-a);
            qc.push(c);
            qCount.push(count+1);
        }
        if(leftLarger(a,c)==1)
        {
            qa.push(a-c);
            qb.push(b);
            qc.push(c+c);
            qCount.push(count+1);
        }
        else if(leftLarger(a,c)==0)
        {
            qa.push(a+a);
            qb.push(b);
            qc.push(c-a);
            qCount.push(count+1);
        }
        if(leftLarger(b,c)==1)
        {
            qa.push(a);
            qb.push(b-c);
            qc.push(c+c);
            qCount.push(count+1);
        }
        else if(leftLarger(b,c)==0)
        {
            qa.push(a);
            qb.push(b+b);
            qc.push(c-b);
            qCount.push(count+1);
        }
    }
}