#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> &a, pair<int,int> &b)
{
    if(a.first==b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> upv;
    vector<pair<int,int>> downv;
    vector<pair<int,int>> v;
    int fa,fb;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        if(i==0)
        {
            fa=a;
            fb=b;
        }
        v.push_back({a,b});
        if(i==0) continue;
        if(a==v[i-1].first) continue;

        pair<int,int> p1,p2;
        p1=v[i];
        p2=v[i-1];
        int st=p1.first;
        int len=p1.first-p2.first;
        if(len<0) len=-len;
        if(st>p2.first)
        {
            st=p2.first;
            downv.push_back({st,len});
        } 
        else
        {
            upv.push_back({st,len});
        }
    }
    if(v[0].second==v[n-1].second)
    {
        if(v[0].first<v[n-1].first)
        {
            upv.push_back({v[0].first, v[n-1].first-v[0].first});
        }
        else
        {
            downv.push_back({v[n-1].first, v[0].first-v[n-1].first});
        }
    }
    sort(v.begin(), v.end(), compare);
    sort(upv.begin(),upv.end(),compare);
    sort(downv.begin(),downv.end(),compare);
    long long area=0;
    int x=upv[0].first;
    long long areaArr[500001]={0};
    int y1,y2;
    y1=v[0].second;
    y2=v[1].second;
    int upi=0;
    int downi=0;
    for(int i=0;i<n-2;i+=2)
    {
        pair<int,int> a,b;
        a=upv[upi];
        b=downv[downi];
        int len=a.second - (x-a.first);
        int isup;
        if(len==b.second - (x-b.first))
        {
            upi++;
            downi++;
            isup=2;
        }
        else if(len>b.second - (x-b.first))
        {
            len=b.second - (x-b.first);
            downi++;
            isup=0;
        }
        else
        {
            upi++;
            isup=1;
        }
        x+=len;
        area+=len*(y2-y1);
        areaArr[i/2+1]=area;
        if(upv.size()==upi) break;
        if(isup==0)
        {
            if(y1==v[i+2].second) y1=v[i+3].second;
            else y1=v[i+2].second;
        }
        else if(isup==1)
        {
            if(y2==v[i+2].second) y2=v[i+3].second;
            else y2=v[i+2].second;
        }
        else if(isup==2)
        {
            if(y1==v[i+2].second) y1=v[i+3].second;
            else y1=v[i+2].second;
            i+=2;
            if(y2==v[i+2].second) y2=v[i+3].second;
            else y2=v[i+2].second;
        }
    }
    long long result=-1;
    int index=0;
    for(int i=0;i<n/2-1;i++)
    {
        long long area1;
        area1=areaArr[i];
        if(area1>area-area1)
        {
            if(result==-1 || result>area1*2-area1)
            {
                result=area1*2-area1;
                index=i;
            }
            else break;
        }
        else
        {
            if(result==-1 || result>area-area1*2)
            {
                result=area-area1*2;
                index=i;
            }
        }
    }
    if(areaArr[index]>area-areaArr[index])
    {
        cout<<area-areaArr[index]<<" "<<areaArr[index];
        return 0;
    }
    cout<<areaArr[index]<<" "<<area-areaArr[index];
}