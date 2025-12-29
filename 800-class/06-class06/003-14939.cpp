#include <iostream>
#include <string>

using namespace std;

int cross[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void turnOn(bool arr[][10], int x, int y)
{
    arr[x][y]=!arr[x][y];
    for(int i=0;i<4;i++)
    {
        int xp=x+cross[i][0];
        int yp=y+cross[i][1];
        if(xp<0 || yp<0 || xp>=10 || yp>=10) continue;
        arr[xp][yp]=!arr[xp][yp];
    }
}

void recurF(bool arr[][10], int idx, int sumV, int *res)
{
    if(idx>18)
    {
        if(*res==-1 || sumV<*res) *res = sumV;
        return;
    }
    if(idx<10)
    {
        bool arr1[10]={0};
        arr1[0]=0;
        int sumV1=sumV;
        for(int i=1;i<=idx;i++)
        {
            if(arr[idx-i][i-1])
            {
                arr1[i]=1;
                turnOn(arr,idx-i,i);
                sumV1++;
            }
        }
        recurF(arr,idx+1,sumV1,res);
        for(int i=0;i<=idx;i++)
        {
            if(arr1[i]) turnOn(arr,idx-i,i);
        }

        bool arr2[10]={0};
        arr2[0]=1;
        
        turnOn(arr,idx,0);
        int sumV2=sumV+1;
        for(int i=1;i<=idx;i++)
        {
            if(arr[idx-i][i-1])
            {
                arr2[i]=1;
                turnOn(arr,idx-i,i);
                sumV2++;
            }
        }
        recurF(arr,idx+1,sumV2,res);
        for(int i=0;i<=idx;i++)
        {
            if(arr2[i]) turnOn(arr,idx-i,i);
        }
        return;
    }
    else
    {
        bool arr1[10]={0};
        int sumV1=sumV;
        for(int i=idx-9;i<10;i++)
        {
            if(arr[idx-i][i-1])
            {
                arr1[i]=1;
                turnOn(arr,idx-i,i);
                sumV1++;
            }
        }
        if(arr[idx-10][9] || (idx==18 && arr[9][9]))
        {
            for(int i=idx-9;i<10;i++)
            {
                if(arr1[i]==1) turnOn(arr,idx-i,i);
            }
            return;
        }
        recurF(arr,idx+1,sumV1,res);
        for(int i=idx-9;i<10;i++)
        {
            if(arr1[i]==1) turnOn(arr,idx-i,i);
        }
        return;
    }
}

int main()
{
    bool arr[10][10];
    for(int i=0;i<10;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<10;j++)
        {
            if(s[j]=='O') arr[i][j]=1;
            else arr[i][j]=0;
        }
    }
    int res=-1;
    recurF(arr,0,0,&res);
    cout<<res;
}