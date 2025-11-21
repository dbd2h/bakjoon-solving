#include <iostream>

using namespace std;

int main()
{
    int n,m,b;
    cin>>n>>m>>b;
    int arr[500][500];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    int res=1e9;
    int h=-1;
    for(int i=0;i<=256;i++)
    {
        int block=b;
        int tot=0;
        for(int x=0;x<n;x++)
        {
            for(int y=0;y<m;y++)
            {
                int cur=arr[x][y];
                if(cur>i)
                {
                    tot+=(cur-i)*2;
                    block+=(cur-i);
                }
                else if(cur<i)
                {
                    tot+=(i-cur);
                    block-=(i-cur);
                }
            }
        }
        if(block<0) break;
        if(res>tot ||(res==tot && h<i))
        {
            res=tot;
            h=i;
        }
    }
    cout<<res<<" "<<h;
}