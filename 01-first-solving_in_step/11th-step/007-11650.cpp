#include <iostream>

void changePosi(int arr1[2], int arr2[2])
{
    int changeX=arr1[0];
    int changeY=arr1[1];

    arr1[0]=arr2[0];
    arr1[1]=arr2[1];
    arr2[0]=changeX;
    arr2[1]=changeY;
}

int main()
{
    int inputPosi;
    std::cin>>inputPosi;

    int posiArr[inputPosi][2]={0};

    for(int i=0;i<inputPosi;i++)
    {
        int x,y;
        std::cin>>x>>y;
        int cur=i+1;
        posiArr[i][0]=x;
        posiArr[i][1]=y;
        while(cur>1)
        {
            if(posiArr[cur-1][0]>posiArr[cur/2-1][0])
            {
                changePosi(posiArr[cur-1],posiArr[cur/2-1]);
            }
            else if(posiArr[cur-1][0]==posiArr[cur/2-1][0])
            {
                if(posiArr[cur-1][1]>posiArr[cur/2-1][1])
                {
                    changePosi(posiArr[cur-1],posiArr[cur/2-1]);
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
            cur/=2;
        }
    }
    for(int len=inputPosi;len>0;len--)
    {
        int tree=1;
        changePosi(posiArr[0],posiArr[len-1]);
        while(tree<(len+1)/2) //밑에 트리 비교하고 자신과 바꾸기 역할
        {
            if(posiArr[tree*2-1][0]>posiArr[tree*2][0]||
                (posiArr[tree*2-1][0]==posiArr[tree*2][0])&&posiArr[tree*2-1][1]>posiArr[tree*2][1]||
                tree==len/2) //왼쪽꺼랑 바꾸기
            {
                if(posiArr[tree*2-1][0]>posiArr[tree-1][0]||
                    (posiArr[tree*2-1][0]==posiArr[tree-1][0])&&posiArr[tree*2-1][1]>posiArr[tree-1][1])
                {
                    changePosi(posiArr[tree-1],posiArr[tree*2-1]);
                }
                else
                {
                    break;
                }
                tree=tree*2;
            }
            else //오른쪽꺼랑 바꾸기
            {
                if(posiArr[tree*2][0]>posiArr[tree-1][0]||
                    (posiArr[tree*2][0]==posiArr[tree-1][0])&&posiArr[tree*2][1]>posiArr[tree-1][1])
                {
                    changePosi(posiArr[tree-1],posiArr[tree*2]);
                }
                else
                {
                    break;
                }
                tree=tree*2+1;
            }
        }
    }
    for(int i=0;i<inputPosi;i++)
    {
        std::cout<<posiArr[i][0]<<" "<<posiArr[i][1]<<"\n";
    }
}