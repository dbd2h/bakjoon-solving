#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

long long binarySearch(vector<pair<long long,long long>> v, int l, int r, int num)
{
    if(l>=r)
    {
        if(v[l].first==num) return v[l].second;
        else if(v[r].first==num) return v[r].second;
        else return 0;
    }
    int middle=(l+r)/2;
    if(v[middle].first==num) return v[middle].second;
    else if(v[middle].first<num) return binarySearch(v, middle+1, r, num);
    else return binarySearch(v,l,middle-1,num);
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t;
    cin>>t;
    for(long long test=0;test<t;test++)
    {
        long long n,x;
        cin>>n>>x;
        long long arr[100000]={0};
        map<long long ,long long> m;
        for(long long i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        vector<pair<long long,long long>> v;
        long long c=0;
        long long s=-1;
        for(long long i=0;i<n;i++)
        {
            if(s!=arr[i])
            {
                if(s==-1)
                {
                    s=arr[i];
                    c=1;
                    continue;
                }
                m.insert({s,c});
                v.push_back({s,c});
                c=1;
                s=arr[i];
                continue;
            }
            c++;
        }
        m.insert({s,c});
        v.push_back({s,c});
        long long len=v.size();
        long long result=0;
        for(long long i=0;i<len;i++)
        {
            if(x==0)
            {
                result+=(m[v[i].first]*(m[v[i].first]-1))/2;
                continue;
            }
            long long num=(v[i].first ^ x);
            if(num<v[i].first) continue;
            result+=m[v[i].first]*m[num];
        }
        cout<<result<<"\n";
    }
    return 0;
}