#include <iostream>
#include <string>

using namespace std;

int main()
{
    bool dp[51][51][51][5]={0}; // AA, C, CA, AB, CB
    dp[0][0][0][0]=true;
    string s;
    cin>>s;
    int slen=s.size();
    int arr[3]={0};
    for(int i=0;i<slen;i++)
    {
        arr[s[i]-'A']++;
    }
    for(int a=0;a<50;a++)
    {
        if(a>arr[0]) break;
        for(int b=0;b<50;b++)
        {
            if(b>arr[1]) break;
            for(int c=0;c<50;c++)
            {
                if(c>arr[2]) break;
                for(int i=0;i<5;i++)
                {
                    if(!dp[a][b][c][i]) continue;
                    if(i==0)
                    {
                        dp[a+1][b][c][0]=true;
                        dp[a][b+1][c][3]=true;
                        dp[a][b][c+1][1]=true;
                    }
                    else if(i==1)
                    {
                        dp[a+1][b][c][2]=true;
                        dp[a][b+1][c][4]=true;
                    }
                    else if(i==2)
                    {
                        dp[a+1][b][c][0]=true;
                        dp[a][b+1][c][3]=true;
                    }
                    else if(i==3)
                    {
                        dp[a+1][b][c][0]=true;
                        dp[a][b][c+1][1]=true;
                    }
                    else if(i==4)
                    {
                        dp[a+1][b][c][0]=true;
                    }
                }
            }
        }
    }
    int res=-1;
    for(int i=0;i<5;i++)
    {
        if(dp[arr[0]][arr[1]][arr[2]][i])
        {
            res=i;
            break;
        }
    }
    if(res==-1)
    {
        cout<<-1;
        return 0;
    }
    int a=arr[0];
    int b=arr[1];
    int c=arr[2];
    s="";
    while(a || b || c)
    {
        if(res==0)
        {
            s="A"+s;
            if(dp[a-1][b][c][0])
            {
                a--;
                res=0;
                continue;
            }
            else if(dp[a-1][b][c][2])
            {
                a--;
                res=2;
                continue;
            }
            else if(dp[a-1][b][c][3])
            {
                a--;
                res=3;
                continue;
            }
            else if(dp[a-1][b][c][4])
            {
                a--;
                res=4;
                continue;
            }
        }
        else if(res==1)
        {
            s="C"+s;
            if(dp[a][b][c-1][0])
            {
                c--;
                res=0;
                continue;
            }
            else if(dp[a][b][c-1][3])
            {
                c--;
                res=3;
                continue;
            }
        }
        else if(res==2)
        {
            s="A"+s;
            if(dp[a-1][b][c][1])
            {
                a--;
                res=1;
                continue;
            }
        }
        else if(res==3)
        {
            s="B"+s;
            if(dp[a][b-1][c][0])
            {
                b--;
                res=0;
                continue;
            }
            else if(dp[a][b-1][c][2])
            {
                b--;
                res=2;
                continue;
            }
        }
        else if(res==4)
        {
            s="B"+s;
            if(dp[a][b-1][c][1])
            {
                b--;
                res=1;
                continue;
            }
        }
        
    }
    cout<<s;
}   