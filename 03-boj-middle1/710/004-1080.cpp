#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[50][50]={0};
    int b[50][50]={0};
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
        {
            a[i][j]=s[j]-'0';
        }
    }
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
        {
            b[i][j]=s[j]-'0';
        }
    }
    int result=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==b[i][j]) continue;
            if(m-j<3 || n-i<3)
            {
                result=-1;
                break;
            }
            for(int r=0;r<3;r++)
            {
                for(int c=0;c<3;c++)
                {
                    a[i+r][j+c]= !a[i+r][j+c];
                }
            }
            result++;
        }
        if(result==-1) break;
    }
    cout<<result;
}