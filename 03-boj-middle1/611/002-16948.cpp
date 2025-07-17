#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    int r1, c1, r2, c2;
    cin>>n;
    cin>>r1>>c1>>r2>>c2;

    int board[200][200]={0};

    queue<pair<int,int>> q;
    queue<int> cq;
    q.push({r1, c1});
    cq.push(0);
    board[r1][c1]=1;
    int result=-1;
    while(!q.empty())
    {
        pair<int,int> p=q.front();
        int r,c,count;
        r=p.first;
        c=p.second;
        count=cq.front();
        if(r==r2 && c==c2)
        {
            result=count;
            break;
        }
        q.pop();
        cq.pop();
        for(int i=-1;i<=1;i+=2)
        {
            if(r-2>=0 && c+i>=0 && c+i<n && board[r-2][c+i]==0)
            {
                board[r-2][c+i]=1;
                q.push({r-2, c+i});
                cq.push(count+1);
            }
            if(c+i*2>=0 && c+i*2<n && board[r][c+i*2]==0)
            {
                board[r][c+i*2]=1;
                q.push({r, c+i*2});
                cq.push(count+1);
            }
            if(r+2<n && c+i>=0 && c+i<n && board[r+2][c+i]==0)
            {
                board[r+2][c+i]=1;
                q.push({r+2, c+i});
                cq.push(count+1);
            }
        }
    }
    cout<<result;
}