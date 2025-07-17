#include <iostream>
#include <string>

using namespace std;

int bitx[50]={0};
int bity[50]={0};
char numArr[4]={'2','3','1','4'};

void twoBit(long long n, int d, int bit[], int *len)
{
    if(n==0)
    {
        *len=d;
        return;
    }
    bit[d]=n%2;
    twoBit(n/2,d+1,bit,len);
}

int main()
{
    int d;
    cin>>d;
    string s;
    cin>>s;
    long long x,y;
    cin>>x>>y;
    int isxminus=0;
    int isyminus=0;
    if(x<0)
    {
        isxminus=1;
        x=-x;
    }
    if(y<0)
    {
        isyminus=1;
        y=-y;
    }
    int xlen, ylen;
    twoBit(x,0,bitx,&xlen);
    twoBit(y,0,bity,&ylen);
    int isup=0;
    for(int i=0;i<s.length();i++)
    {
        if(bitx[i]==0)
        {
            if(isup==1)
            {
                if(s[s.length()-i-1]==numArr[(0+isxminus*2)%4])
                {
                    s[s.length()-i-1]=numArr[(2+isxminus*2)%4];
                    isup=0;
                }
                else if(s[s.length()-i-1]==numArr[(1+isxminus*2)%4])
                {
                    s[s.length()-i-1]=numArr[(3+isxminus*2)%4];
                    isup=0;
                }
                else if(s[s.length()-i-1]==numArr[(2+isxminus*2)%4])
                {
                    s[s.length()-i-1]=numArr[(0+isxminus*2)%4];
                }
                else if(s[s.length()-i-1]==numArr[(3+isxminus*2)%4])
                {
                    s[s.length()-i-1]=numArr[(1+isxminus*2)%4];
                }
            }
        }
        else
        {
            if(isup==0)
            {
                if(s[s.length()-i-1]==numArr[(0+isxminus*2)%4])
                {
                    s[s.length()-i-1]=numArr[(2+isxminus*2)%4];
                }
                else if(s[s.length()-i-1]==numArr[(1+isxminus*2)%4])
                {
                    s[s.length()-i-1]=numArr[(3+isxminus*2)%4];
                }
                else if(s[s.length()-i-1]==numArr[(2+isxminus*2)%4])
                {
                    s[s.length()-i-1]=numArr[(0+isxminus*2)%4];
                    isup=1;
                }
                else if(s[s.length()-i-1]==numArr[(3+isxminus*2)%4])
                {
                    s[s.length()-i-1]=numArr[(1+isxminus*2)%4];
                    isup=1;
                }
            }
        }
    }
    if(isup==1)
    {
        cout<<-1;
        return 0;
    }
    for(int i=0;i<s.length();i++) // positive: 3->2, 4->1, 2 3 1 4
    {
        if(bity[i]==0)
        {
            if(isup==1)
            {
                if(s[s.length()-i-1]==numArr[(1-isyminus)%4])
                {
                    s[s.length()-i-1]=numArr[(0+isyminus)%4];
                    isup=0;
                }
                else if(s[s.length()-i-1]==numArr[(3-isyminus)%4])
                {
                    s[s.length()-i-1]=numArr[(2+isyminus)%4];
                    isup=0;
                }
                else if(s[s.length()-i-1]==numArr[(0+isyminus)%4])
                {
                    s[s.length()-i-1]=numArr[(1-isyminus)%4];
                }
                else if(s[s.length()-i-1]==numArr[(2+isyminus)%4])
                {
                    s[s.length()-i-1]=numArr[(3-isyminus)%4];
                }
            }
        }
        else
        {
            if(isup==0)
            {
                if(s[s.length()-i-1]==numArr[(1-isyminus)%4])
                {
                    s[s.length()-i-1]=numArr[(0+isyminus)%4];
                }
                else if(s[s.length()-i-1]==numArr[(3-isyminus)%4])
                {
                    s[s.length()-i-1]=numArr[(2+isyminus)%4];
                }
                else if(s[s.length()-i-1]==numArr[(0+isyminus)%4])
                {
                    s[s.length()-i-1]=numArr[(1-isyminus)%4];
                    isup=1;
                }
                else if(s[s.length()-i-1]==numArr[(2+isyminus)%4])
                {
                    s[s.length()-i-1]=numArr[(3-isyminus)%4];
                    isup=1;
                }
            }
        }
    }
    if(isup==1)
    {
        cout<<-1;
        return 0;
    }
    cout<<s;
}

// 0 = 2,3, 1 = 1,4

// 341 -> 432 -> 431 -> 442 -> 441