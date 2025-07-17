#include <iostream>

using namespace std;

int euclid(int num1, int num2)
{
    if(num1%num2==0)
    {
        return num2;
    }
    return euclid(num2, num1%num2);
}

int main()
{
    int broNum, pos;
    cin>>broNum>>pos;
    int diffArr[broNum];
    int broPos;
    for(int i=0;i<broNum;i++)
    {
        cin>>broPos;
        diffArr[i]=pos-broPos;
        if(diffArr[i]<0)
        {
            diffArr[i]=-diffArr[i];
        }
    }
    int gcd=diffArr[0];
    for(int i=1;i<broNum;i++)
    {
        gcd=euclid(gcd, diffArr[i]);
    }
    cout<<gcd<<"\n";

}

// 동생과의 차이들의 최대공약수