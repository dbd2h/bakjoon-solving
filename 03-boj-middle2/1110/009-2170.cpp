#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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
    sort(startV.begin(),startV.end());
    sort(endV.begin(),endV.end());
    int c=1;
    int res=0;
    int i=1;
    int j=0;
    int cur=startV[0];
    while(true)
    {
        if(j==n) break;
        if(i==n)
        {
            res+=(endV[j]-cur);
            cur=endV[j];
            j++;
            c--;
        }
        else if(startV[i]<=endV[j])
        {
            if(c!=0)
            {
                res+=(startV[i]-cur);
            }
            cur=startV[i];
            i++;
            c++;
        }
        else
        {
            res+=(endV[j]-cur);
            cur=endV[j];
            j++;
            c--;
        }
    }
    cout<<res;
}