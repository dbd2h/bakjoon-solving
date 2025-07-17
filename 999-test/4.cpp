#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(vector<int> v1, vector<int> v2)
{
    if(v1[1]>v2[1])
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string s="asf";
    s[1]='b';
    cout<<s;
    vector <vector<int>> v;
    
    vector<int> b;
    for(int j=0;j<3;j++)
    {
        vector<int> a;
        for(int i=0;i<3;i++)
        {
            int num;
            cin>>num;
            a.push_back(num);
        }
        v.push_back(a);
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<v[i][j]<<' ';
        }
        cout<<"\n";
    }
}