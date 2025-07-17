#include <iostream>

using namespace std;

int isNotContain(int num, int *numArr, int len);
int sub(int num1, int num2);

int main()
{
    int chan;
    int bNum;
    int bArr[10];
    cin>>chan>>bNum;
    for(int i=0;i<bNum;i++)
    {
        cin>>bArr[i];
    }
    int min=5000000;
    if(bNum==0)
    {
        min=sub(0,chan)+1;
    }
    for(int i=0;i<bNum;i++)
    {
        if(bArr[i]==0)
        {
            break;
        }
        if(i==bNum-1)
        {
            min=sub(0,chan)+1;
        }
    }
    if(min>sub(chan, 100))
    {
        min=sub(chan,100);
    }
    for(int i=1;i<=1000010;i++)
    {
        int c=isNotContain(i, bArr, bNum);
        if(c==0)
        {
            continue;
        }
        if(min>c+sub(i,chan))
        {
            min=c+sub(i,chan);
        }
    }
    cout<<min;
    
}

int isNotContain(int num, int *numArr, int len)
{
    int tens=1;
    int click=1;
    while(num>=tens*10)
    {
        tens*=10;
        click++;
    }
    while(num)
    {
        for(int i=0;i<len;i++)
        {
            if(num/tens==numArr[i])
            {
                return 0;
            }
        }
        num%=tens;
        tens/=10;
    }
    if(num==0&&tens!=0)
    {
        for(int i=0;i<len;i++)
        {
            if(numArr[i]==0)
            {
                return 0;
            }
        }
    }
    return click;
}

int sub(int num1, int num2)
{
    int result=num1-num2;
    if(result<0)
        result=-result;
    return result;
}