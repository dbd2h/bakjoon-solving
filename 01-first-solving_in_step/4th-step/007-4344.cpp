#include <iostream>

int main()
{
    int caseCount;
    std::cin>>caseCount;

    for(int classCount=0;classCount<caseCount;classCount++)
    {
        int student;
        std::cin>>student;

        float scoreTotal=0;
        int scoreArr[student];
        for(int score=0;score<(sizeof(scoreArr)/sizeof(int));score++)
        {
            int scoreValue;
            std::cin>>scoreValue;
            scoreTotal += (float)scoreValue;
            scoreArr[score]=scoreValue;
        }
        float scoreAvg=scoreTotal/student;
        int upAvg=0;
        for(int i=0;i<student;i++)
        {
            if(scoreArr[i]>scoreAvg)
            {
                upAvg++;
            }
        }
        std::cout<<std::fixed;
        std::cout.precision(3);
        std::cout<<(float)upAvg/(float)student*100<<"%"<<std::endl;
    }
}