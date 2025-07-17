#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> s;
    int n;
    cin>>n;
    int aArr[4000]={0};
    int bArr[4000]={0};
    int cArr[4000]={0};
    int dArr[4000]={0};
    for(int i=0;i<n;i++)
    {
        cin>>aArr[i]>>bArr[i]>>cArr[i]>>dArr[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            s.push_back(aArr[i]+bArr[j]);
        }
    }
    sort(s.begin(), s.end());
    long long res=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int sumV=cArr[i]+dArr[j];
            int l=lower_bound(s.begin(),s.end(),-sumV)-s.begin();
            int u=upper_bound(s.begin(),s.end(),-sumV)-s.begin();
            res+=(u-l);
        }
    }
    cout<<res;
}