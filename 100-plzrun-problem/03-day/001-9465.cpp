#include <iostream>

int main()
{
    int count;
    std::cin>>count;
    for(int i=0;i<count;i++)
    {
        int inputNum;
        std::cin>>inputNum;

        int sticker[2][inputNum];
        int stickerTotal[2][inputNum];

        for(int j=0;j<inputNum*2;j++)
        {
            std::cin>>sticker[j/inputNum][j%inputNum];
        }
        for(int j=0;j<inputNum;j++)
        {
            if(j==0)
            {
                stickerTotal[0][0]=sticker[0][0];
                stickerTotal[1][0]=sticker[1][0];
                continue;
            }
            else if(j==1)
            {
                stickerTotal[0][1]=sticker[0][1]+sticker[1][0];
                stickerTotal[1][1]=sticker[1][1]+sticker[0][0];
                continue;
            }
            stickerTotal[0][j]=(stickerTotal[1][j-1]>stickerTotal[1][j-2]?stickerTotal[1][j-1]:stickerTotal[1][j-2])+sticker[0][j];
            stickerTotal[1][j]=(stickerTotal[0][j-1]>stickerTotal[0][j-2]?stickerTotal[0][j-1]:stickerTotal[0][j-2])+sticker[1][j];
        }
        if(stickerTotal[0][inputNum-1]>stickerTotal[1][inputNum-1])
        {
            std::cout<<stickerTotal[0][inputNum-1]<<"\n";
        }
        else
        {
            std::cout<<stickerTotal[1][inputNum-1]<<"\n";
        }
    }
}

/*
100 300 10 30
200 400 20 40

*/