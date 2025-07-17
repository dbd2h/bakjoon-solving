#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Student
{
    std::string name;
    int kor;
    int eng;
    int mat;
};

void change(std::vector<Student> &vec, int i1, int i2)
{
    Student changeVec1=vec[i1];
    Student changeVec2=vec[i2];
    vec[i1]=changeVec2;
    vec[i2]=changeVec1;
}

bool compare(const Student &stu1, const Student &stu2)
{
    if(stu1.kor==stu2.kor)
    {
        if(stu1.eng==stu2.eng)
        {
            if(stu1.mat==stu2.mat)
            {
                return stu1.name<stu2.name;
            }
            else
            {
                return stu1.mat>stu2.mat;
            }
        }
        else
        {
            return stu1.eng<stu2.eng;
        }
    }
    else
    {
        return stu1.kor>stu2.kor;
    }
}

void heapSortInput(std::vector<Student> &v)
{
    int vSize=v.size();
    while(vSize-1)
    {
        if(compare(v[vSize-1],v[vSize/2-1]))
        {
            change(v, vSize-1, vSize/2-1);
        }
        else
        {
            break;
        }
        vSize/=2;
    }
}

int main()
{
    std::vector<Student> vec;
    int inputNum;
    std::cin>>inputNum;
    for(int i=0;i<inputNum;i++)
    {
        Student s;
        std::cin>>s.name>>s.kor>>s.eng>>s.mat;
        vec.push_back(s);
        heapSortInput(vec);
    }
    for(int i=0;i<inputNum;i++)
    {
        int vecSize=inputNum-i;
        change(vec, 0, vecSize-1);
        std::cout<<vec[inputNum-i-1].name<<"\n";
        int start=1;
        while((vecSize-1)/2>=start)
        {
            if(vecSize!=start*2+1)
            {
                if(compare(vec[start*2-1],vec[start*2]))
                {
                    if(compare(vec[start-1],vec[start*2-1]))
                    {
                        break;
                    }
                    change(vec,start-1,start*2-1);
                    start=start*2;
                }
                else
                {
                    if(compare(vec[start-1],vec[start*2]))
                    {
                        break;
                    }
                    change(vec,start-1,start*2);
                    start=start*2+1;
                }
            }
            else
            {
                if(compare(vec[start-1],vec[start*2-1]))
                {
                    break;
                }
                change(vec,start-1,start*2-1);
                start=start*2;
            }
        }
    }
}