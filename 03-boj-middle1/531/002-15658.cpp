#include <iostream>

#define MAX 1'000'000'001

using namespace std;

int numArr[11]={0};
int oper[4]={0};
int operMinus[4]={0};
int nummax=-MAX;
int nummin=MAX;
int operOrder[12]={0};

void cal(int n, int cur);

void operMinimize(int n, int totalOper, int totCur, int op)
{
    if(op==3)
    {
        operMinus[3]=totalOper-totCur-(n-1);
        oper[0]-=operMinus[0];
        oper[1]-=operMinus[1];
        oper[2]-=operMinus[2];
        oper[3]-=operMinus[3];
        cal(n, 0);
        oper[0]+=operMinus[0];
        oper[1]+=operMinus[1];
        oper[2]+=operMinus[2];
        oper[3]+=operMinus[3];
        return;
    }
    int futSum=0;
    for(int i=op+1;i<4;i++)
    {
        futSum+=oper[i];
    }
    for(int i=oper[op];i>=0;i--)
    {
        if(totalOper-(n-1)-totCur-i-futSum>0 || totalOper-(n-1)-totCur-i<0)
        {
            continue;
        }
        operMinus[op]=i;
        operMinimize(n, totalOper, totCur+i, op+1);
    }
}

void cal(int n, int cur)
{
    if(n-1==cur)
    {
        int result=numArr[0];
        for(int i=0;i<n-1;i++)
        {
            switch(operOrder[i])
            {
                case 0:
                    result+=numArr[i+1];
                    break;
                case 1:
                    result-=numArr[i+1];
                    break;
                case 2:
                    result*=numArr[i+1];
                    break;
                case 3:
                    result/=numArr[i+1];
                    break;
            }
        }
        if(nummax<result)
        {
            nummax = result;
        }
        if(nummin>result)
        {
            nummin = result;
        }
        return;
    }

    for(int i=0;i<4;i++)
    {
        if(oper[i]==0)
        {
            continue;
        }
        oper[i]--;
        operOrder[cur]=i;
        cal(n, cur+1);
        oper[i]++;
    }
}

int main()
{
    int n;
    cin>>n;
    int totalOper=0;
    for(int i=0;i<n;i++)
    {
        cin>>numArr[i];
    }
    for(int i=0;i<4;i++)
    {
        cin>>oper[i];
        totalOper+=oper[i];
    }
    operMinimize(n, totalOper, 0, 0);
    cout<<nummax<<"\n"<<nummin;
}