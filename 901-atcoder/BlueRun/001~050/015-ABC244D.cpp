#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
typedef long long ll;
typedef long double lld;

using namespace std;

int main()
{
    char arr1[3];
    char arr2[3];
    for(int i=0;i<3;i++) cin>>arr1[i];
    for(int i=0;i<3;i++) cin>>arr2[i];
    int l=0;
    while(arr1[l]!=arr2[0]) l++;
    for(int i=0;i<3;i++)
    {
        int idx=(i+l)%3;
        if(arr1[idx]!=arr2[i])
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}