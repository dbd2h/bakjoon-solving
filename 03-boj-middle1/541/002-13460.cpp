#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

char board[10][10]={0};

int marbleMove(int x, int y, int i, int n)
{
    //i=0: up, i=1: down, i=2: left, i=3: right
    int c=0;
    if(i==0)
    {
        while(x-1>=0 && board[x-1][y]!='#')
        {
            x--;
            c++;
            if(board[x][y]=='O')
            {
                return -1;
            }
        }
        return c;
    }
    else if(i==1)
    {
        while(x+1<n && board[x+1][y]!='#')
        {
            x++;
            c++;
            if(board[x][y]=='O')
            {
                return -1;
            }
        }
        return c;
    }
    else if(i==2)
    {
        while(y-1>=0 && board[x][y-1]!='#')
        {
            y--;
            c++;
            if(board[x][y]=='O')
            {
                return -1;
            }
        }
        return c;
    }
    else if(i==3)
    {
        while(y+1<n && board[x][y+1]!='#')
        {
            y++;
            c++;
            if(board[x][y]=='O')
            {
                return -1;
            }
        }
        return c;
    }
    else
    {
        return 0;
    }
    
}

int main()
{

    int n,m;
    pair<int,int> marbleR;
    pair<int,int> marbleB;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        string input;
        cin>>input;
        for(int j=0;j<m;j++)
        {
            if(input[j]=='R')
            {
                board[i][j]='.';
                marbleR.first=i;
                marbleR.second=j;
            }
            else if(input[j]=='B')
            {
                board[i][j]='.';
                marbleB.first=i;
                marbleB.second=j;
            }
            else
            {
                board[i][j]=input[j];
            }
        }
    }

    queue<pair<int,int>> mB;
    queue<pair<int,int>> mR;
    queue<int> c;
    mB.push(marbleB);
    mR.push(marbleR);
    c.push(1);
    int result=-1;
    while(!mB.empty())
    {
        int count;
        marbleB=mB.front();
        marbleR=mR.front();
        count=c.front();
        mB.pop();
        mR.pop();
        c.pop();
        if(count>10)
        {
            result=-1;
            break;
        }
        int mBx, mBy, mRx, mRy;
        mBx=marbleB.first;
        mBy=marbleB.second;
        mRx=marbleR.first;
        mRy=marbleR.second;
        int Bi, Ri;
        Bi=marbleMove(mBx, mBy, 0, n);
        Ri=marbleMove(mRx, mRy, 0, n);
        if(Ri==-1 && Bi!=-1)
        {
            result=count;
            break;
        }
        else if(Bi!=-1)
        {
            if(mBy==mRy && mBx-Bi==mRx-Ri)
            {
                if(mBx<mRx)
                {
                    mB.push({mBx-Bi, mBy});
                    mR.push({mRx-Ri+1, mRy});
                    c.push(count+1);
                }
                else
                {
                    mB.push({mBx-Bi+1, mBy});
                    mR.push({mRx-Ri, mRy});
                    c.push(count+1);
                }
            }
            else
            {
                mB.push({mBx-Bi, mBy});
                mR.push({mRx-Ri, mRy});
                c.push(count+1);
            }
        }

        Bi=marbleMove(mBx, mBy, 1, n);
        Ri=marbleMove(mRx, mRy, 1, n);
        if(Ri==-1 && Bi!=-1)
        {
            result=count;
            break;
        }
        else if(Bi!=-1)
        {
            if(mBy==mRy && mBx+Bi==mRx+Ri)
            {
                if(mBx<mRx)
                {
                    mB.push({mBx+Bi-1, mBy});
                    mR.push({mRx+Ri, mRy});
                    c.push(count+1);
                }
                else
                {
                    mB.push({mBx+Bi, mBy});
                    mR.push({mRx+Ri-1, mRy});
                    c.push(count+1);
                }
            }
            else
            {
                mB.push({mBx+Bi, mBy});
                mR.push({mRx+Ri, mRy});
                c.push(count+1);
            }
        }

        Bi=marbleMove(mBx, mBy, 2, m);
        Ri=marbleMove(mRx, mRy, 2, m);
        if(Ri==-1 && Bi!=-1)
        {
            result=count;
            break;
        }
        else if(Bi!=-1)
        {
            if(mBx==mRx && mBy-Bi==mRy-Ri)
            {
                if(mBy<mRy)
                {
                    mB.push({mBx, mBy-Bi});
                    mR.push({mRx, mRy-Ri+1});
                    c.push(count+1);
                }
                else
                {
                    mB.push({mBx, mBy-Bi+1});
                    mR.push({mRx, mRy-Ri});
                    c.push(count+1);
                }
            }
            else
            {
                mB.push({mBx, mBy-Bi});
                mR.push({mRx, mRy-Ri});
                c.push(count+1);
            }
        }
        
        Bi=marbleMove(mBx, mBy, 3, m);
        Ri=marbleMove(mRx, mRy, 3, m);
        if(Ri==-1 && Bi!=-1)
        {
            result=count;
            break;
        }
        else if(Bi!=-1)
        {
            if(mBx==mRx && mBy+Bi==mRy+Ri)
            {
                if(mBy<mRy)
                {
                    mB.push({mBx, mBy+Bi-1});
                    mR.push({mRx, mRy+Ri});
                    c.push(count+1);
                }
                else
                {
                    mB.push({mBx, mBy+Bi});
                    mR.push({mRx, mRy+Ri-1});
                    c.push(count+1);
                }
            }
            else
            {
                mB.push({mBx, mBy+Bi});
                mR.push({mRx, mRy+Ri});
                c.push(count+1);
            }
        }
    }
    cout<<result;
}