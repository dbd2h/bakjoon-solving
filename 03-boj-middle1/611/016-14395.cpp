#include <iostream>
#include <queue>
#include <string>


using namespace std;

int main()
{
    int s,t;
    cin>>s>>t;
    if(s==t)
    {
        cout<<0;
        return 0;
    }
    if(t==0)
    {
        cout<<'-';
        return 0;
    }
    if(s==0)
    {
        cout<<-1;
        return 0;
    }
    queue<long long> q;
    queue<string> strQ;
    strQ.push("");
    q.push(s);
    int isDiv=0;
    int oneCount[1000]={0};
    while(!q.empty())
    {
        long long num=q.front();
        string str=strQ.front();
        if(num==t)
        {
            cout<<str;
            return 0;
        }
        q.pop();
        strQ.pop();
        if(num<=31622 && num!=1)
        {
            q.push(num*num);
            strQ.push(str+'*');
        } 
        if(num+num<=1000000000)
        {
            q.push(num+num);
            strQ.push(str+'+');
        } 
        if(isDiv==0)
        {
            q.push(1);
            strQ.push(str+'/');
            isDiv=1;
        }
    }
    cout<<-1;
}

// 7 -> 49 -> 14 -> 