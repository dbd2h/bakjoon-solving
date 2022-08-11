#include <iostream>

using namespace std;

int main()
{
    int alpha[26]={};
    for(int i=0;i<sizeof(alpha)/sizeof(int);i++)
    {
        alpha[i]=-1;
    }
    char str[101]="";
    cin>>str;
    for(int i=0;i<sizeof(str)/sizeof(char);i++)
    {
        int strToNum=str[i]-'a';
        if(strToNum<0)
        {
            break;
        }
        if(alpha[strToNum]==-1)
        {
            alpha[strToNum]=i;
        }
    }
    for(int i=0;i<sizeof(alpha)/sizeof(int)-1;i++)
    {
        cout<<alpha[i]<<" ";
    }
    cout<<alpha[25]<<"\n";
}
