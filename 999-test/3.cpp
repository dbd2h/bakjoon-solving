#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    int len=s.length();
    int spell=0;
    char a='a';
    for(int i=0;i<len;i++)
    {
        if(s[i]==' ')
        {
            spell=' ';
        }
        else if(s[i]-'Z'<=0)
        {
            spell=s[i]+n;
            if(spell>90)
            {
                spell-=26;
            }
        }
        else
        {
            spell=s[i]+n;
            if(spell>122)
            {
                spell-=26;
            }
        }
        cout<<char(spell);
        answer+=char(spell);
        cout<<"\n"<<s<<"\n";
    }
    return answer;
}

int main()
{
    string s="asdf";
    int n=1;
    cout<<solution(s,n);
}