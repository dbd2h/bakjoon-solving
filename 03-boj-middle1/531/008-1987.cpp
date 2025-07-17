#include <iostream>
#include <stack>

using namespace std;

char alphabet[20][20];
int maxC=0;
int passedAlpha[26]={0};

void alphaMax(int x, int y, int count, int r, int c)
{
    char a;
    int order;
    if(x-1>=0)
    {
        a=alphabet[x-1][y];
        order=a-'A';
        if(passedAlpha[order]==0)
        {
            passedAlpha[order]=1;
            alphaMax(x-1, y, count+1, r, c);
            passedAlpha[order]=0;
        }
    }
    if(y-1>=0)
    {
        a=alphabet[x][y-1];
        order=a-'A';
        if(passedAlpha[order]==0)
        {
            passedAlpha[order]=1;
            alphaMax(x, y-1, count+1, r, c);
            passedAlpha[order]=0;
        }
    }
    if(x+1<r)
    {
        a=alphabet[x+1][y];
        order=a-'A';
        if(passedAlpha[order]==0)
        {
            passedAlpha[order]=1;
            alphaMax(x+1, y, count+1, r, c);
            passedAlpha[order]=0;
        }
    }
    if(y+1<c)
    {
        a=alphabet[x][y+1];
        order=a-'A';
        if(passedAlpha[order]==0)
        {
            passedAlpha[order]=1;
            alphaMax(x, y+1, count+1, r, c);
            passedAlpha[order]=0;
        }
    }
    if(count>maxC)
    {
        maxC=count;
    }
}

int main()
{
    int r,c;
    cin>>r>>c;
    
    for(int i=0;i<r;i++)
    {
        char s[21];
        cin>>s;
        for(int j=0;j<c;j++)
        {
            alphabet[i][j]=s[j];
        }
    }
    passedAlpha[alphabet[0][0]-'A']=1;
    alphaMax(0, 0, 1, r, c);
    cout<<maxC;
}