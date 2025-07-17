#include <iostream>

using namespace std;

int min(int n1, int n2);

int main()
{
    int c;
    cin>>c;
    int price[c][3]={0};
    int res[c][3]={0};
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>price[i][j];
        }
    }
    res[0][0]=price[0][0];
    res[0][1]=price[0][1];
    res[0][2]=price[0][2];
    for(int i=1;i<c;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(res[i-1][(j+1)%3]>res[i-1][(j+2)%3])
            {
                res[i][j]=res[i-1][(j+2)%3]+price[i][j];
            }
            else
            {
                res[i][j]=res[i-1][(j+1)%3]+price[i][j];
            }
        }
    }
    int min;
    if(res[c-1][0]<res[c-1][1])
    {
        if(res[c-1][0]<res[c-1][2])
            min=res[c-1][0];
        else
            min=res[c-1][2];
    }
    else
    {
        if(res[c-1][1]<res[c-1][2])
            min=res[c-1][1];
        else
            min=res[c-1][2];
    }
    cout<<min;
}