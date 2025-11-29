#include <iostream>
#include <string>

using namespace std;


string sumF(string &s1, string &s2)
{
    string s;
    if(s1=="0" && s2=="0")
    {
        return "0";
    }
    int idx1=s1.size();
    int idx2=s2.size();
    bool isUp=0;
    while(idx1>0 || idx2>0)
    {
        int num1=0;
        int len1=0;
        if(idx1>0)
        {
            if(idx1>=8)
            {
                idx1-=8;
                len1=8;
            } 
            else
            {
                len1=idx1;
                idx1=0;
            }
            num1=stoi(s1.substr(idx1,len1));
        } 
        int num2=0;
        int len2=0;
        if(idx2>0)
        {
            if(idx2>=8)
            {
                idx2-=8;
                len2=8;
            } 
            else
            {
                len2=idx2;
                idx2=0;
            }
            num2=stoi(s2.substr(idx2,len2));
        }
        int sumV=num1+num2;
        if(isUp) sumV+=1;
        if(sumV/(int)(1e8)==1)
        {
            isUp=1;
            sumV-=1e8;
        }
        else isUp=0;
        string plus=to_string(sumV);
        int maxLen=len1;
        if(len1<len2) maxLen=len2;
        for(int i=plus.size();i<maxLen;i++)
        {
            plus="0"+plus;
        }
        s=plus+s;
    }
    if(isUp) s+="1";
    return s;
}

int main()
{
    string s1="165580141";
    string s2="63245986";
    cout<<sumF(s1,s2);
}
