#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> startV;
    vector<int> endV;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        startV.push_back(a);
        endV.push_back(b);
    }
    sort(startV.begin(), startV.end());
    sort(endV.begin(),endV.end());
    int c=1;
    int res=1;
    int cur=startV[0];
    int i=1;
    int j=0;
    while(true)
    {
        if(i==n) break;
        if(startV[i]<endV[j])
        {
            c++;
            if(c>res) res=c;
            i++;
        }
        else
        {
            c--;
            j++;
        }
    }
    cout<<res;
}