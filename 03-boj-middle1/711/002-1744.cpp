#include <iostream>
#include <algorithm>

using namespace std;

bool desc(int a, int b)
{
    return a>b;
}

int main()
{
    int n;
    cin>>n;
    int plusArr[50]={0};
    int minusArr[50]={0};
    int plusC=0;
    int minusC=0;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        if(num>0)
        {
            plusArr[plusC]=num;
            plusC++;
        }
        else
        {
            minusArr[minusC]=num;
            minusC++;
        }
    }
    sort(plusArr, plusArr+plusC, desc);
    sort(minusArr, minusArr+minusC);
    int result=0;
    for(int i=0;i<plusC;i++)
    {
        if(i+1<plusC && plusArr[i+1]!=1)
        {
            result+=plusArr[i]*plusArr[i+1];
            i++;
            continue;
        }
        else
        {
            result+=plusArr[i];
        }
    }
    for(int i=0;i<minusC;i++)
    {
        if(i+1<minusC)
        {
            result+=minusArr[i]*minusArr[i+1];
            i++;
            continue;
        }
        else
        {
            result+=minusArr[i];
        }
    }
    cout<<result;
}