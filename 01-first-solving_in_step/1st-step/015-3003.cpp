#include <iostream>

int main()
{
    int king,queen,look,bishop,knight, pawn;
    std::cin>>king>>queen>>look>>bishop>>knight>>pawn;

    std::cout<<1-king<<" "<<1-queen<<" "<<2-look<<" "<<2-bishop<<" "<<2-knight<<" "<<8-pawn<<std::endl;
    return 0;
}