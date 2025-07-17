#include <stdio.h>

struct date
{
    int year;
    int month;
    int day;
};

struct student
{
    int number;
    char name[20];
    struct date *dd;
    double grade;
};

int main()
{
    struct date d={2003, 3, 20};
    struct student s={20240001, "Kim", NULL, 4.3};

    s.dd=&d;

    printf("%d %s %f\n", s.number, s.name, s.grade);
    printf("%d년 %d월 %d일\n", (*s.dd).year, (*s.dd).month, (*s.dd).day);
}


void alphaCheck(int n, int k, int cur, int used, int count)
{
    int nowUsed=used;
    int nowAlpha[26]={0};
    for(int i=cur;i<n;i++)
    {
        if(count+n-i<=maxC)
        {
            return;
        }
        int pass=0;
        for(int j=0;j<15;j++)
        {
            if(str[i][j]==0)
            {
                break;
            }
            int curAlpha=str[i][j];
            if(alpha[curAlpha]==1)
            {
                continue;
            }
            if(nowUsed>=k)
            {
                for(int m=0;m<nowUsed-used;m++)
                {
                    int num=nowAlpha[m];
                    alpha[num]=0;
                    nowAlpha[m]=0;
                }
                nowUsed=used;
                pass=1;
                break;
            }
            alpha[curAlpha]=1;
            nowAlpha[nowUsed-used]=curAlpha;
            nowUsed++;
        }
        if(pass)
        {
            continue;
        }
        alphaCheck(n,k,i+1,nowUsed,count+1);
        for(int m=0;m<nowUsed-used;m++)
        {
            int num=nowAlpha[m];
            alpha[num]=0;
            nowAlpha[m]=0;
        }
        nowUsed=used;
    }
    if(maxC<count)
    {
        maxC=count;
    }
}
