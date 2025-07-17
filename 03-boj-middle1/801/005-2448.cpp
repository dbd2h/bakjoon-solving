#include <iostream>

using namespace std;

void starMaker(int n, int h, int w)
{
    if(n==3)
    {
        if(h%3==1 && w%2==1)
        {
            cout<<" ";
            return;
        }
        else
        {
            cout<<"*";
            return;
        }
    }
    else if(n/2>h%n)
    {
        starMaker(n/2,h,w);
        return;
    }//12345, 234, 3
    // n=6, h=4,5,6
    // n=12, h=7,8...,
    //n=6, h=5, w=5
    //n=24, h=17, w=21, 34, 11~23
    if(w%n>h%n*2-n && w%n<h*2+1-(h%n*2-n)) // h=12, n=24, 0~24, 36
    {
        cout<<" ";
        return;
    }
    else
    {
        starMaker(n/2,h,w);
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<2*i+1;j++)
        {
            starMaker(n,i,j); // n=6, i=4, j=2
        }
        for(int j=0;j<n-i;j++)
        {
            cout<<" ";
        }
        cout<<"\n";
    }
}