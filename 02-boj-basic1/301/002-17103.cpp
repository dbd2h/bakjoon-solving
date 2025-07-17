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
    int arr[MILL+1]={1,1}; //소수 아니면 1 맞으면 0
    primeArrMaker(arr);
    int count;
    cin>>count;
    
    for(int i=0;i<count;i++)
    {
        int input;
        cin>>input;
        int num1=3;
        int num2=input-num1;
        int parCount=0;
        if(input==4)
        {
            parCount+=1;
        }
        while(num1<=num2)
        {
            if(arr[num1]==0&&arr[num2]==0)
            {
                parCount++;
            }
            num1+=2;
            num2-=2;
        }
        cout<<parCount<<"\n";
    }
}