#include <iostream>
#include <string>

using namespace std;

int main()
{
    int freq;
    cin>>freq;

    for(int count=0;count<freq;count++)
    {
        int input;
        cin>>input;
        string str;
        cin>>str;
        for(int i=0;i<str.length();i++)
        {
            for(int j=0;j<input;j++)
            {
                cout<<str[i];
            }
        }
        cout<<"\n";
    }
    return 0;
}