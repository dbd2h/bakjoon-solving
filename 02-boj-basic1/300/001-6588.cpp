#include <iostream>

#define MILL 1'000'000

using namespace std;

void primeArrMaker(int arr[])
{
    for(int i=2;i<1000;i+=2)
    {
        if(arr[i]==0)
        {
            for(int j=i*i;j<=MILL;j+=i)
            {
                arr[j]=1;
            }
        }
        if(i==2)
        {
            i-=1;
        }
    }
}

int main()
{
    int arr[MILL+1]={1,1}; // 소수면 0 아니면 1
    primeArrMaker(arr);
    int inputNum,num1,num2;
    bool isGold=false;
    cin>>inputNum;
    cin.tie(NULL);

    while(inputNum)
    {
        num1=3;
        num2=inputNum-num1;
        while(num1<=num2)
        {
            if(arr[num1]==0&&arr[num2]==0)
            {
                isGold=true;
                break;
            }
            num1+=2;
            num2-=2;
        }
        if(isGold)
        {
            cout<<inputNum<<" = "<<num1<<" + "<<num2<<"\n";
        }
        else
        {
            cout<<"Goldbach's conjecture is wrong."<<"\n";
        }
        cin>>inputNum;
    }
}