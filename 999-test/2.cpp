#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int arr1[100]={0};
    int arr2[100]={0};
    vector<int> v;
    for(int i=0;i<100;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<100;i++)
    {
        cin>>arr2[i];
        if(arr1[i]!=arr2[i])
        {
            v.push_back(i+1);
        }
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<"\n";
    }
}