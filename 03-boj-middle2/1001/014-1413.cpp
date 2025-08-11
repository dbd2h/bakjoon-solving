#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

string arrToString(int arr[])
{
    string s;
    for(int i=1;i<=20;i++)
    {
        if(!arr[i]) continue;
        for(int j=0;j<arr[i];j++)
        {
            if(!s.size()) s=to_string(i);
            else s+=' '+to_string(i);
        }
    }
    return s;
}

long long gcd(long long n1, long long n2)
{
    if(n2==0) return n1;
    return gcd(n2, n1%n2);
}

int main()
{
    int n,m;
    cin>>n>>m;
    map<string,long long> sMap;
    queue<string> q;
    string s="1";
    q.push(s);
    sMap[s]=1;
    if(n==1)
    {
        cout<<"1/1";
        return 0;
    }
    long long dem=0;
    long long mo=0;
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        istringstream ss(s);
        string buffer;
        int sumV=0;
        int cV=0;
        int arr[21]={0};
        while(getline(ss,buffer,' '))
        {
            int num=stoi(buffer);
            sumV+=num;
            cV++;
            arr[num]++;
        }
        arr[1]++;
        string next=arrToString(arr);
        if(sMap[next]==0 && sumV<19) q.push(next);
        sMap[next]+=sMap[s];
        if(sumV+1==n)
        {
            dem+=sMap[s];
            if(cV+1<=m) mo+=sMap[s];
        }
        arr[1]--;
        for(int i=1;i<20;i++)
        {
            if(!arr[i]) continue;
            long long c=arr[i];
            arr[i]--;
            arr[i+1]++;
            next=arrToString(arr);
            if(sMap[next]==0 && sumV<19) q.push(next);
            sMap[next]+=c*i*sMap[s];
            if(sumV+1==n)
            {
                dem+=c*i*sMap[s];
                if(cV<=m) mo+=c*i*sMap[s];
            }
            arr[i]++;
            arr[i+1]--;
        }
    }
    long long gcdV=gcd(dem,mo);
    cout<<mo/gcdV<<"/"<<dem/gcdV;
}

