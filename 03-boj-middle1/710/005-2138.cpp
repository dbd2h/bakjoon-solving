#include <iostream>
#include <string>

using namespace std;

char changer01(char a)
{
    if(a=='0') return '1';
    else if(a=='1') return '0';
    else return 'a';
}

int main()
{
    int n;
    cin>>n;

    string begin;
    string end;
    cin>>begin>>end;
    int result=-1;
    for(int i=0;i<4;i++)
    {
        int countA=0;
        string beginA=begin;
        if(i==0)
        {
            beginA[0]=changer01(begin[0]);
            beginA[1]=changer01(begin[1]);
            countA++;
        }
        else if(i==1)
        {
            beginA[n-2]=changer01(beginA[n-2]);
            beginA[n-1]=changer01(beginA[n-1]);
            countA++;
        }
        else if(i==2)
        {
            beginA[0]=changer01(begin[0]);
            beginA[1]=changer01(begin[1]);
            countA++;
            beginA[n-2]=changer01(beginA[n-2]);
            beginA[n-1]=changer01(beginA[n-1]);
            countA++;
        }
        for(int i=0;i<n-2;i++)
        {
            if(beginA[i]==end[i]) continue;
            beginA[i]=changer01(beginA[i]);
            beginA[i+1]=changer01(beginA[i+1]);
            beginA[i+2]=changer01(beginA[i+2]);
            countA++;
        }
        if(beginA[0]!=end[0] || beginA[n-2]!=end[n-2] || beginA[n-1]!=end[n-1]) continue;
        
        if(result==-1 || result>countA) result=countA;
    }

    cout<<result;
}