#include <iostream>

using namespace std;

int num[10]={0};
int square[3][3]={0};
int inputS[3][3]={0};

int abs(int n)
{
    if(n<0) n=-n;
    return n;
}

int main()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>inputS[i][j];
        }
    }
    int minV=100000000;
    for(int i=1;i<=9;i++)
    {
        if(num[i]==1) continue;
        square[0][0]=i;
        num[i]=1;

        for(int j=1;j<=9;j++)
        {
            if(num[j]==1) continue;
            int n13=15-square[0][0]-j;
            if(n13>9 || n13<=0 || num[n13]==1) continue;
            square[0][1]=j;
            num[j]=1;
            square[0][2]=n13;
            num[n13]=1;

            for(int k=1;k<=9;k++)
            {
                if(num[k]==1) continue;
                int n31=15-square[0][0]-k;
                if(n31>9 || n31<=0 || num[n31]==1) continue;
                square[1][0]=k;
                num[k]=1;
                square[2][0]=n31;
                num[n31]=1;

                for(int l=1;l<=9;l++)
                {
                    if(num[l]==1) continue;
                    int n23=15-square[1][0]-l;
                    int n32=15-square[0][1]-l;
                    int n33=15-square[0][0]-l;

                    if(n32>9 || n32<=0 || num[n32]==1) continue;
                    if(n23>9 || n23<=0 || num[n23]==1) continue;
                    if(n33>9 || n33<=0 || num[n33]==1) continue;
                    if(square[0][2]+square[2][0]+l!=15) continue;
                    if(square[0][2]+n23+n33!=15) continue;
                    if(square[2][0]+n32+n33!=15) continue;
                    square[1][1]=l;
                    square[1][2]=n23;
                    square[2][1]=n32;
                    square[2][2]=n33;
                    int res=0;
                    for(int i=0;i<3;i++)
                    {
                        for(int j=0;j<3;j++)
                        {
                            res+=abs(square[i][j]-inputS[i][j]);
                        }
                    }
                    if(minV>res) minV=res;
                }
                
                num[k]=0;
                num[n31]=0;
                square[1][0]=0;
                square[2][0]=0;
            }
            
            num[j]=0;
            num[n13]=0;
            square[0][1]=0;
            square[0][2]=0;
        }

        num[i]=0;
        square[0][0]=0;
    }
    cout<<minV;
}