#include <iostream>

using namespace std;

int sticker[100][2]={0};

int spin[4][2]={{0,0},{0,1},{1,0},{1,1}};

int main()
{
    int h,w,n;
    cin>>h>>w>>n;
    int maxW=0;
    for(int i=0;i<n;i++)
    {
        cin>>sticker[i][0]>>sticker[i][1];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=0;k<4;k++)
            {
                int sp1=spin[k][0];
                int sp2=spin[k][1];
                int s1H=sticker[i][sp1];
                int s1W=sticker[i][1-sp1];
                int s2H=sticker[j][sp2];
                int s2W=sticker[j][1-sp2];
                if(s1H+s2H<=h && s1W<=w && s2W<=w || s1W+s2W<=w && s1H<=h && s2H<=h)
                {
                    int sizeP=s1H*s1W+s2H*s2W;
                    if(maxW<sizeP) maxW=sizeP;
                }
            }
        }
    }
    cout<<maxW;
}