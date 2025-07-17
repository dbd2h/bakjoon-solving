#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int N,S;
    cin>>N>>S;
    if(N<=20)
    {
        int arr[1024]={0};
        queue<int> q;
        
        int num;
        
        for(int i=0;i<N;i++)
        {
            cin>>num;
            int s=q.size();
            for(int j=0;j<s;j++)
            {
                int n=q.front();
                q.pop();
                q.push(n);
                q.push(n+num);
            }
            q.push(num);
        }
        int res=0;
        int s=q.size();
        for(int i=0;i<s;i++)
        {
            num=q.front();
            q.pop();
            if(num==S) res++;
        }
        cout<<res;
        return 0;
    }
    queue<int> q;
    
    int num;
    map<int,int> numMap;
    
    for(int i=0;i<20;i++)
    {
        cin>>num;
        int s=q.size();
        for(int j=0;j<s;j++)
        {
            int n=q.front();
            q.pop();
            q.push(n);
            q.push(n+num);
        }
        q.push(num);
    }
    int s=q.size();
    for(int i=0;i<s;i++)
    {
        numMap[q.front()]++;
        q.pop();
    }
    numMap[0]++;
    for(int i=20;i<N;i++)
    {
        cin>>num;
        int s=q.size();
        for(int j=0;j<s;j++)
        {
            int n=q.front();
            q.pop();
            q.push(n);
            q.push(n+num);
        }
        q.push(num);
    }
    long long res=0;
    s=q.size();
    for(int i=0;i<s;i++)
    {
        res+=(numMap[S-q.front()]);
        q.pop();
    }
    res+=numMap[S];
    if(S==0) res--;
    cout<<res;
}