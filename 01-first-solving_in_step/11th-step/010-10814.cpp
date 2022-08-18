#include <iostream>
#include <string>

void changeArr(int arrA[2],int arrB[2])
{
    int changeAge,changeIndex;
    changeAge=arrA[0];
    changeIndex=arrA[1];
    arrA[0]=arrB[0];
    arrA[1]=arrB[1];
    arrB[0]=changeAge;
    arrB[1]=changeIndex;
}

int main()
{
    int inputNum;
    std::cin>>inputNum;
    int ageArr[inputNum][2]={0};
    std::string strArr[inputNum];

    for(int i=0;i<inputNum;i++)
    {
        int age;
        std::string name;
        std::cin>>age>>name;
        ageArr[i][0]=age;
        ageArr[i][1]=i;
        strArr[i]=name;
        int cur=i+1;

        while(cur-1)
        {
            if(ageArr[cur-1][0]>ageArr[cur/2-1][0]||
                (ageArr[cur-1][0]==ageArr[cur/2-1][0]&&ageArr[cur-1][1]>ageArr[cur/2-1][1]))
            {
                changeArr(ageArr[cur-1],ageArr[cur/2-1]);
            }
            else
            {
                break;
            }
            cur/=2;
        }
    }
    changeArr(ageArr[0],ageArr[inputNum-1]);

    for(int len=inputNum-1;len>0;len--)
    {
        int tree=1;
        while(len/2>=tree)
        {
            if(ageArr[tree*2-1][0]>ageArr[tree*2][0]||
                (ageArr[tree*2-1][0]==ageArr[tree*2][0]&&ageArr[tree*2-1][1]>ageArr[tree*2][1])||
                len==tree*2)
            {
                if(ageArr[tree*2-1][0]>ageArr[tree-1][0]||
                    (ageArr[tree*2-1][0]==ageArr[tree-1][0]&&ageArr[tree*2-1][1]>ageArr[tree-1][1]))
                {
                    changeArr(ageArr[tree*2-1],ageArr[tree-1]);
                }
                else
                {
                    break;
                }
                tree=tree*2;
            }
            else
            {
                if(ageArr[tree*2][0]>ageArr[tree-1][0]||
                    (ageArr[tree*2][0]==ageArr[tree-1][0]&&ageArr[tree*2][1]>ageArr[tree-1][1]))
                {
                    changeArr(ageArr[tree*2],ageArr[tree-1]);
                }
                else
                {
                    break;
                }
                tree=tree*2+1;
            }
        }
        changeArr(ageArr[0],ageArr[len-1]);
    }
    for(int i=0;i<inputNum;i++)
    {
        std::cout<<ageArr[i][0]<<" "<<strArr[ageArr[i][1]]<<"\n";
    }
}