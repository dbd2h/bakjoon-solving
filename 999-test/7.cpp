#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
}