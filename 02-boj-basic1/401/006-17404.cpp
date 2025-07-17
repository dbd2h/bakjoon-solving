#include <iostream>

using namespace std;

int main()
{
    int c;
    cin>>c;
    long long arr[c+1][3]={0};
    long long res[c+1][3]={0};
    for(int i=1;i<=c;i++)
    {
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    int min=1000001;
    for(int i=0;i<3;i++)
    {
        res[1][i]=arr[1][i];
        res[1][(i+1)%3]=1000001;
        res[1][(i+2)%3]=1000001;
        for(int j=2;j<=c;j++)
        {
            if(res[j-1][0]>res[j-1][1])
            {
                res[j][2]=res[j-1][1]+arr[j][2];
            }
            else
            {
                res[j][2]=res[j-1][0]+arr[j][2];
            }
            if(res[j-1][0]>res[j-1][2])
            {
                res[j][1]=res[j-1][2]+arr[j][1];
            }
            else
            {
                res[j][1]=res[j-1][0]+arr[j][1];
            }
            if(res[j-1][1]>res[j-1][2])
            {
                res[j][0]=res[j-1][2]+arr[j][0];
            }
            else
            {
                res[j][0]=res[j-1][1]+arr[j][0];
            }
        }
        if(res[c][(i+1)%3]>res[c][(i+2)%3])
        {
            if(min>res[c][(i+2)%3])
            {
                min=res[c][(i+2)%3];
            }
        }
        else
        {
            if(min>res[c][(i+1)%3])
            {
                min=res[c][(i+1)%3];
            }
        }
    }
    cout<<min;
}