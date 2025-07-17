#include <iostream>
#include <string>

using namespace std;

char arr[500][500];

int cross[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int main()
{
    int r,c;
    cin>>r>>c;
    for(int i=0;i<r;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<c;j++)
        {
            arr[i][j]=s[j];
        }
    }
    int res=1;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]!='W') continue;
            for(int p=0;p<4;p++)
            {
                int xp,yp;
                xp=cross[p][0];
                yp=cross[p][1];
                if(i+xp<0 || i+xp>=r || j+yp<0 || j+yp>=c) continue;
                if(arr[i+xp][j+yp]=='S')
                {
                    res=0;
                    break;
                }
                if(arr[i+xp][j+yp]=='.')
                {
                    arr[i+xp][j+yp]='D';
                }
            }
            if(!res) break;
            
        }
        if(!res) break;
    }
    cout<<res<<"\n";
    if(res==0) return 0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<arr[i][j];
        }
        cout<<"\n";
    }
}