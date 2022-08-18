#include <iostream>
#include <string>

void chessMaker(char (*arr)[8])
{
    char blackWhite='B';
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            arr[i][j]=blackWhite;
            
            blackWhite=(blackWhite=='B')?'W':'B';
        }
        blackWhite=(blackWhite=='B')?'W':'B';
    }
}

int main()
{
    char chessArr[8][8];
    chessMaker(chessArr);

    int column, row;
    std::cin>>column>>row;
    std::string totalChessArr[column];

    for(int i=0;i<column;i++)
    {
        std::cin>>totalChessArr[i];
    }
    
    int min=64;
    
    for(int i=0;i<=column-8;i++)
    {
        for(int j=0;j<=row-8;j++)
        {
            int momentDiff=0;
            int y=0;
            while(y<8)
            {
                int x=0;
                while(x<8)
                {
                    if(totalChessArr[y+i][x+j]!=chessArr[y][x])
                    {
                        momentDiff++;
                    }
                    x++;
                }
                y++;
            }
            if(momentDiff>32)
            {
                momentDiff=64-momentDiff;
            }
            if(min>momentDiff)
            {
                min=momentDiff;
            }
        }
    }
    std::cout<<min<<std::endl;
}