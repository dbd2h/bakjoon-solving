#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int s1Len=s1.size();
    int s2Len=s2.size();
    int lcs[1001][1001]={0};
    for(int i=0;i<s1Len;i++)
    {
        for(int j=0;j<s2Len;j++)
        {
            if(s1[i]==s2[j])
            {
                lcs[i+1][j+1]=lcs[i][j]+1;
            }
            else
            {
                lcs[i+1][j+1]=lcs[i+1][j];
                if(lcs[i+1][j+1]<lcs[i][j+1]) lcs[i+1][j+1]=lcs[i][j+1];
            }
        }
    }
    cout<<lcs[s1Len][s2Len]<<"\n";
    int x=s1Len;
    int y=s2Len;
    char resArr[1000];
    int count=0;
    while(x!=0 && y!=0)
    {
        if(lcs[x][y]==lcs[x][y-1])
        {
            y--;
        }
        else if(lcs[x][y]==lcs[x-1][y])
        {
            x--;
        }
        else if(lcs[x][y]-1==lcs[x-1][y-1])
        {
            resArr[count]=s1[x-1];
            x--;
            y--;
            count++;
        }
    }
    for(int i=lcs[s1Len][s2Len]-1;i>=0;i--)
    {
        cout<<resArr[i];
    }
}