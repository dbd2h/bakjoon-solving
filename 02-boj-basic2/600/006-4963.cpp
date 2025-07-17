#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int r,c;
    cin>>c>>r;
    while(r!=0&&c!=0)
    {
        int map[52][52]={0};
        int check[52][52]={0};
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                cin>>map[i][j];
            }
        }
        int tot=0;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                if(map[i][j]==1&&check[i][j]==0)
                {
                    tot++;
                    queue<pair<int,int>> q;
                    pair<int,int> a={i,j};
                    q.push(a);
                    check[i][j]=1;
                    while(!q.empty())
                    {
                        a=q.front();
                        q.pop();
                        int r1,c1;
                        r1=a.first;
                        c1=a.second;
                        for(int n=-1;n<=1;n+=2)
                        {
                            if(map[r1+n][c1]==1&&check[r1+n][c1]==0)
                            {
                                check[r1+n][c1]=1;
                                q.push({r1+n,c1});
                            }
                            if(map[r1][c1+n]==1&&check[r1][c1+n]==0)
                            {
                                check[r1][c1+n]=1;
                                q.push({r1,c1+n});
                            }
                            if(map[r1+n][c1+n]==1&&check[r1+n][c1+n]==0)
                            {
                                check[r1+n][c1+n]=1;
                                q.push({r1+n,c1+n});
                            }
                            if(map[r1-n][c1+n]==1&&check[r1-n][c1+n]==0)
                            {
                                check[r1-n][c1+n]=1;
                                q.push({r1-n,c1+n});
                            }
                        }
                    }
                }
            }
        }
        cout<<tot<<"\n";
        cin>>c>>r;  
    }
}