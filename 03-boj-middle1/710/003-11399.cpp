#include <iostream>
#include <algorithm>
#include <vector>

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
    sort(v.begin(), v.end());
    int result=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            result+=v[j];
        }
    }
    cout<<result;
}