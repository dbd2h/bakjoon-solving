#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int move[8][2]={{2,-1},{2,1},{1,-2},{1,2},{-2,-1},{-2,1},{-1,-2},{-1,2}};
    for(int count=0;count<n;count++)
    {
        int l;
        cin>>l;
        int chess[304][304]={0};
        for(int i=0;i<l+4;i++)
        {
            for(int j=0;j<l+4;j++)
            {
                if(i<=1||i>=l+2||j<=1||j>=l+2)
                {
                    chess[i][j]=-1;
                }
            }
        }
        int a,b;
        cin>>a>>b;
        queue<pair<int,int>> q;
        q.push({a+2,b+2});
        int f1,f2;
        cin>>f1>>f2;
        pair<int,int> p;
        chess[a+2][b+2]=1;
        int finish=0;
        while(!q.empty())
        {
            p=q.front();
            q.pop();
            a=p.first;
            b=p.second;
            if(a==f1+2&&b==f2+2)
            {
                break;
            }
            for(int i=0;i<8;i++)
            {
                int r,c;
                r=move[i][0];
                c=move[i][1];
                if(chess[a+r][b+c]==0)
                {
                    chess[a+r][b+c]=chess[a][b]+1;
                    q.push({a+r,b+c});
                    if(a+r==f1+2&&b+c==f2+2)
                    {
                        finish=1;
                        break;
                    }
                }
            }
            if(finish==1)
            {
                break;
            }
        }
        cout<<chess[f1+2][f2+2]-1<<"\n";
    }
}