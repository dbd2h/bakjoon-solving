#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int aArr[100];
    for(int i=0;i<n;i++)
    {
        cin>>aArr[i];
    }
    int m;
    cin>>m;
    int bArr[100];
    for(int i=0;i<m;i++)
    {
        cin>>bArr[i];
    }
    int st[100][2];
    int stLen=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(aArr[i]!=bArr[j]) continue;
            int inputIdx=-1;
            for(int k=stLen-1;k>=0;k--)
            {
                int cur=st[k][0];
                int idx=st[k][1];
                if(cur>=aArr[i])
                {
                    if(idx<j) inputIdx=k+1;
                    break;
                }
                if(k==0)
                {
                    inputIdx=0;
                    break;
                }
            }
            if(stLen==0)
            {
                st[0][0]=aArr[i];
                st[0][1]=j;
                stLen++;
                break;
            }
            if(inputIdx==-1) continue;
            st[inputIdx][0]=aArr[i];
            st[inputIdx][1]=j;
            stLen=inputIdx+1;
            break;
        }
    }
    cout<<stLen<<"\n";
    for(int i=0;i<stLen;i++)
    {
        cout<<st[i][0]<<" ";
    }
}