#include <iostream>

using namespace std;

int chicken[13][2]={0};
int house[100][2]={0};
int map[50][50]={0};

int chickenDis[100][13]={0};

int chickenRem[13]={0};

int abs(int n)
{
    return n>0 ? n : -n;
}

void combi(int n, int m, int c, int rem, int chickenC, int houseC, int *minDis)
{
    if(c>=chickenC)
    {
        int s=0;
        for(int i=0;i<houseC;i++)
        {
            int mv=1000000;
            for(int j=0;j<chickenC;j++)
            {
                if(chickenRem[j]==1) continue;
                if(mv>chickenDis[i][j]) mv=chickenDis[i][j];
            }
            s+=mv;
        }
        if(*minDis>s) *minDis=s;
        return;
    }
    if(chickenC-rem>m) // m: 치킨집이 몇개 있어야 하는지. chickenC: 치킨집이 총 몇개있는지. c: 몇번째 치킨집인지. rem: 몇개 지웠는지. chickenC-c 
    {
        chickenRem[c]=1;
        combi(n,m,c+1,rem+1,chickenC,houseC,minDis);
        chickenRem[c]=0;
    }
    if(c<rem+m)
    {
        combi(n,m,c+1,rem,chickenC,houseC,minDis);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    int houseC=0;
    int chickenC=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>map[i][j];
            if(map[i][j]==1)
            {
                house[houseC][0]=i;
                house[houseC][1]=j;
                houseC++;
            }
            else if(map[i][j]==2)
            {
                chicken[chickenC][0]=i;
                chicken[chickenC][1]=j;
                chickenC++;
            }
        }
    }
    for(int i=0;i<houseC;i++)
    {
        for(int j=0;j<chickenC;j++)
        {
            int hx=house[i][0];
            int hy=house[i][1];
            int cx=chicken[j][0];
            int cy=chicken[j][1];
            chickenDis[i][j]=abs(hx-cx)+abs(hy-cy);
        }
    }
    int minDis=10000000;
    combi(n,m,0,0,chickenC,houseC,&minDis);
    cout<<minDis;
}