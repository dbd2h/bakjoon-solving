#include <iostream>
#include <string>
#include <queue>

using namespace std;

int map[1000][1000]={0};
int check[1000][1000]={0};
int minCheck[1000][1000]={0};

int ab(int n)
{
    if(n>0)
    {
        return n;
    }
    else
    {
        return -n;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
        {
            map[i][j]=s[j]-'0';
        }
    }
    queue<pair<int,int>> q;
    queue<int> qCount;
    q.push({0,0});
    qCount.push(1);
    check[0][0]=1;
    int result=1000000;
    while(!q.empty())
    {
        int a,b,count;
        a=q.front().first;
        b=q.front().second;
        count=qCount.front();
        q.pop();
        qCount.pop();
        if(a-1>=0 && check[a-1][b]==0 && map[a-1][b]==0)
        {
            q.push({a-1,b});
            qCount.push(count+1);
            check[a-1][b]=count+1;
        }
        if(a+1<n && check[a+1][b]==0 && map[a+1][b]==0)
        {
            q.push({a+1,b});
            qCount.push(count+1);
            check[a+1][b]=count+1;
        }
        if(b-1>=0 && check[a][b-1]==0 && map[a][b-1]==0)
        {
            q.push({a,b-1});
            qCount.push(count+1);
            check[a][b-1]=count+1;
        }
        if(b+1<m && check[a][b+1]==0 && map[a][b+1]==0)
        {
            q.push({a,b+1});
            qCount.push(count+1);
            check[a][b+1]=count+1;
        }
    }
    if(check[n-1][m-1]==0)
    {
        q.push({n-1,m-1});
        qCount.push(-1);
        check[n-1][m-1]=-1;
        while(!q.empty())
        {
            int a,b,count;
            a=q.front().first;
            b=q.front().second;
            count=qCount.front();
            q.pop();
            qCount.pop();
            if(a-1>=0 && check[a-1][b]==0 && map[a-1][b]==0)
            {
                q.push({a-1,b});
                qCount.push(count-1);
                check[a-1][b]=count-1;
            }
            if(a+1<n && check[a+1][b]==0 && map[a+1][b]==0)
            {
                q.push({a+1,b});
                qCount.push(count-1);
                check[a+1][b]=count-1;
            }
            if(b-1>=0 && check[a][b-1]==0 && map[a][b-1]==0)
            {
                q.push({a,b-1});
                qCount.push(count-1);
                check[a][b-1]=count-1;
            }
            if(b+1<m && check[a][b+1]==0 && map[a][b+1]==0)
            {
                q.push({a,b+1});
                qCount.push(count-1);
                check[a][b+1]=count-1;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(map[i][j]==0)
                {
                    continue;
                }
                int plusMin=0;
                int minusMin=0;
                if(i-1>=0 && check[i-1][j]!=0)
                {
                    if(check[i-1][j]>0 && (plusMin==0 || plusMin>check[i-1][j]))
                    {
                        plusMin=check[i-1][j];
                    }
                    else if(check[i-1][j]<0 && (minusMin==0 || minusMin<check[i-1][j]))
                    {
                        minusMin=check[i-1][j];
                    }
                }
                if(i+1<n && check[i+1][j]!=0)
                {
                    if(check[i+1][j]>0 && (plusMin==0 || plusMin>check[i+1][j]))
                    {
                        plusMin=check[i+1][j];
                    }
                    else if(check[i+1][j]<0 && (minusMin==0 || minusMin<check[i+1][j]))
                    {
                        minusMin=check[i+1][j];
                    }
                }
                if(j-1>=0 && check[i][j-1]!=0)
                {
                    if(check[i][j-1]>0 && (plusMin==0 || plusMin>check[i][j-1]))
                    {
                        plusMin=check[i][j-1];
                    }
                    else if(check[i][j-1]<0 && (minusMin==0 || minusMin<check[i][j-1]))
                    {
                        minusMin=check[i][j-1];
                    }
                }
                if(j+1<m && check[i][j+1]!=0)
                {
                    if(check[i][j+1]>0 && (plusMin==0 || plusMin>check[i][j+1]))
                    {
                        plusMin=check[i][j+1];
                    }
                    else if(check[i][j+1]<0 && (minusMin==0 || minusMin<check[i][j+1]))
                    {
                        minusMin=check[i][j+1];
                    }
                }
                if(plusMin!=0 && minusMin!=0)
                {
                    if(result>plusMin-minusMin+1)
                    {
                        result=plusMin-minusMin+1;
                    }
                }
            }
        }
    }
    else
    {
        result=check[n-1][m-1];
        q.push({n-1,m-1});
        qCount.push(-1);
        minCheck[n-1][m-1]=-1;
        while(!q.empty())
        {
            int a,b,count;
            a=q.front().first;
            b=q.front().second;
            count=qCount.front();
            q.pop();
            qCount.pop();
            if(a-1>=0 && minCheck[a-1][b]==0 && map[a-1][b]==0)
            {
                q.push({a-1,b});
                qCount.push(count-1);
                minCheck[a-1][b]=count-1;
            }
            if(a+1<n && minCheck[a+1][b]==0 && map[a+1][b]==0)
            {
                q.push({a+1,b});
                qCount.push(count-1);
                minCheck[a+1][b]=count-1;
            }
            if(b-1>=0 && minCheck[a][b-1]==0 && map[a][b-1]==0)
            {
                q.push({a,b-1});
                qCount.push(count-1);
                minCheck[a][b-1]=count-1;
            }
            if(b+1<m && minCheck[a][b+1]==0 && map[a][b+1]==0)
            {
                q.push({a,b+1});
                qCount.push(count-1);
                minCheck[a][b+1]=count-1;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(map[i][j]==0)
                {
                    continue;
                }
                int minusMin=0;
                int plusMin=0;
                if(i-1>=0 && check[i-1][j]!=0)
                {
                    if(plusMin==0 || plusMin>check[i-1][j])
                    {
                        plusMin=check[i-1][j];
                    }
                    if(minusMin==0 || minusMin<minCheck[i-1][j])
                    {
                        minusMin=minCheck[i-1][j];
                    }
                }
                if(i+1<n && check[i+1][j]!=0)
                {
                    if(plusMin==0 || plusMin>check[i+1][j])
                    {
                        plusMin=check[i+1][j];
                    }
                    if(minusMin==0 || minusMin<minCheck[i+1][j])
                    {
                        minusMin=minCheck[i+1][j];
                    }
                }
                if(j-1>=0 && check[i][j-1]!=0)
                {
                    if(plusMin==0 || plusMin>check[i][j-1])
                    {
                        plusMin=check[i][j-1];
                    }
                    if(minusMin==0 || minusMin<minCheck[i][j-1])
                    {
                        minusMin=minCheck[i][j-1];
                    }
                }
                if(j+1<m && check[i][j+1]!=0)
                {
                    if(plusMin==0 || plusMin>check[i][j+1])
                    {
                        plusMin=check[i][j+1];
                    }
                    if(minusMin==0 || minusMin<minCheck[i][j+1])
                    {
                        minusMin=minCheck[i][j+1];
                    }
                }
                if(plusMin!=0 && minusMin!=0)
                {
                    if(result>plusMin-minusMin+1)
                    {
                        result=plusMin-minusMin+1;
                    }
                }
            }
        }
    }
    if(result==1000000)
    {
        cout<<-1;
    }
    else
    {
        cout<<result;
    }
}