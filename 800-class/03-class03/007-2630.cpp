#include <iostream>

using namespace std;

void recurF(bool arr[128][128], int l, int x, int y, int *white, int *blue)
{
    bool cur=arr[x][y];
    for(int i=x;i<x+l;i++)
    {
        for(int j=y;j<y+l;j++)
        {
            if(arr[i][j]!=cur)
            {
                recurF(arr,l/2,x,y,white,blue);
                recurF(arr,l/2,x,y+l/2,white,blue);
                recurF(arr,l/2,x+l/2,y,white,blue);
                recurF(arr,l/2,x+l/2,y+l/2,white,blue);
                return;
            }
        }
    }
    if(cur==1) (*blue)++;
    else (*white)++;
    return;
}

int main()
{
    int n;
    cin>>n;
    bool arr[128][128];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    int blue=0;
    int white=0;
    recurF(arr,n,0,0,&white,&blue);
    cout<<white<<"\n"<<blue;

}