#include <iostream>

using namespace std;

int main()
{
    int p[3][2]={0};
    for(int i=0;i<3;i++)
    {
        cin>>p[i][0]>>p[i][1];
    }
    int x1=p[1][0]-p[0][0];
    int y1=p[1][1]-p[0][1];
    int x2=p[2][0]-p[1][0];
    int y2=p[2][1]-p[1][1];
    int result=x1*y2-x2*y1;
    if(result<0) cout<<-1;
    else if(result>0) cout<<1;
    else cout<<0;
}