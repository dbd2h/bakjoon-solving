#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int len=s.length();
    vector<string> v;
    char arr[50];
    int oper=0;
    for(int i=0;i<len;i++)
    {
        string num;
        while(i<len && s[i]!='+' && s[i]!='-')
        {
            num+=s[i];
            i++;
        }
        v.push_back(num);
        arr[oper]=s[i];
        oper++;
    }
    oper--;
    int numArr[50]={0};
    for(int i=0;i<oper+1;i++)
    {
        numArr[i]= stoi(v[i]);
    }
    int sumArr[50]={0};
    int sumV=numArr[0];
    int index=0;
    for(int i=1;i<oper+1;i++)
    {
        if(arr[i-1]=='-')
        {
            sumArr[index]=sumV;
            index++;
            sumV=0;
        }
        sumV+=numArr[i];
    }
    sumArr[index]=sumV;
    index++;
    int result=sumArr[0];
    for(int i=1;i<index;i++)
    {
        result-=sumArr[i];
    }
    cout<<result;
}