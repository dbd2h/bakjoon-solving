#include <iostream>
#include <string>
#include <queue>

using namespace std;
int numArr[10]={0};
char operArr[9];
int isPart[9]={0};

void plusPart(int n, int c, long long *maxN, long long val)
{
    if(n/2<=c)
    {
        if(*maxN<val) *maxN = val;
        return;
    }
        long long v=val;
        if(operArr[c]=='+') v+=numArr[c+1];
        else if(operArr[c]=='-') v-=numArr[c+1];
        else if(operArr[c]=='*') v*=numArr[c+1];
        plusPart(n, c+1, maxN, v);
        if(n/2==c+1) return;
        v=val;
        long long part=numArr[c+1];
        if(operArr[c+1]=='+') part+=numArr[c+2];
        else if(operArr[c+1]=='-') part-=numArr[c+2];
        else if(operArr[c+1]=='*') part*=numArr[c+2];
        if(operArr[c]=='+') v+=part;
        else if(operArr[c]=='-') v-=part;
        else if(operArr[c]=='*') v*=part;
        isPart[c+1]=1;
        plusPart(n,c+2,maxN,v);
        isPart[c+1]=0;
}

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    long long result=-100000000000000000;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            numArr[i/2]=s[i]-'0';
        }
        else
        {
            operArr[i/2]=s[i];
        }
    }
    plusPart(n,0,&result,numArr[0]);
    cout<<result;
}