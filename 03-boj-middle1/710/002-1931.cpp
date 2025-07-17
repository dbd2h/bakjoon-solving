#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<long long,long long> a, pair<long long,long long> b)
{
    long long numa1, numa2 ,numb1, numb2;
    numa1=a.first;
    numa2=a.second;
    numb1=b.first;
    numb2=b.second;

    if(numa2<numb2)
    {
        return true;
    }
    else if(numa2==numb2 && numa1<numb1) return true;
    else return false;
}

int main()
{
    int n;
    vector<pair<long long,long long>> v;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        long long a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), cmp);

    int time=0;
    int c=0;
    for(int i=0;i<n;i++)
    {
        pair<long long, long long> p=v[i];
        if(time<=p.first)
        {
            time=p.second;
            c++;
        }
    }
    cout<<c;
}