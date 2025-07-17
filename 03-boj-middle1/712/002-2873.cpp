#include <iostream>

using namespace std;

int main()
{
    int r,c;
    cin>>r>>c;
    int roller[1000][1000]={0};
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>roller[i][j];
        }
    }

    if(r%2==1)
    {
        for(int i=0;i<r;i++)
        {
            if(i%2==0)
            {
                for(int j=0;j<c-1;j++)
                {
                    cout<<'R';
                }
                if(i<r-1) cout<<'D';
            }
            else
            {
                for(int j=0;j<c-1;j++)
                {
                    cout<<'L';
                }
                cout<<'D';
            }
        }

        return 0;
    }
    else if(c%2==1)
    {
        for(int i=0;i<c;i++)
        {
            if(i%2==0)
            {
                for(int j=0;j<r-1;j++)
                {
                    cout<<'D';
                }
                if(i<c-1) cout<<'R';
            }
            else
            {
                for(int j=0;j<r-1;j++)
                {
                    cout<<'U';
                }
                cout<<'R';
            }
        }

        return 0;
    }

    int x,y,minV;
    minV=1000;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if((i+j)%2==0) continue;
            if(roller[i][j]<minV)
            {
                x=i;
                y=j;
                minV=roller[i][j];
            }
        }
    }
    int toRight=1;
    for(int i=0;i<r;i++)
    {
        if(x==i+1 || x==0)
        {
            int toUp=0;
            int curY=y;
            if(toRight==0) curY=c-y-1;
            for(int j=0;j<c-1;j++)
            {
                if(j!=curY)
                {
                    toUp==0 ? cout<<'D' : cout<<'U';
                    toUp=!toUp;
                }
                toRight==1 ? cout<<'R' : cout<<'L';
            }
            if(r!=2) cout<<'D';
            i++;
            toRight=!toRight;
            if(i==r-1 || (y==c-1 && toRight==0) || (y==0 && toRight==1)) continue;
            cout<<'D';
            continue;
        }
        else
        {
            for(int j=0;j<c-1;j++)
            {
                toRight==1 ? cout<<'R' : cout<<'L';
            }
            toRight=!toRight;
            if(i<r-1) cout<<'D';
        }
    }
    
}// 움직인 거리가 홀수인 애들 중 최소값 구해서 빼기
