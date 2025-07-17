#include <iostream>
#include <vector>

using namespace std;

vector<pair<double,double>> v;
vector<pair<double,double>> v1;

double shoe(double sta)
{
    double size=0;
    if(sta==1)
    {
        int len=v.size();
        for(int i=0;i<len;i++)
        {
            double x1,x2,y1,y2;
            x1=v[i].first;
            y1=v[i].second;
            x2=v[(i+1)%len].first;
            y2=v[(i+1)%len].second;
            size+=x1*y2-y1*x2;
        }
        return size/2;
    }
    int len=v1.size();
    for(int i=0;i<len;i++)
    {
        double x1,x2,y1,y2;
        x1=v1[i].first;
        y1=v1[i].second;
        x2=v1[(i+1)%len].first;
        y2=v1[(i+1)%len].second;
        size+=x1*y2-y1*x2;
    }
    return size/2;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    for(double i=0;i<n;i++)
    {
        double a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    double line;
    cin>>line;
    int isUp=-1;
    int indexutod=-1;
    int indexdtou=-1;
    int sta=0; // 1이면 전부다 위. 2이면 전부다 아래
    for(int i=0;i<n;i++)
    {
        double y=v[i].second;
        if(y<line && isUp==1)
        {
            indexutod=i;
        }
        if(y>=line && isUp==0)
        {
            indexdtou=i;
        }
        if(y>=line)
        {
            isUp=1;
        }
        else
        {
            isUp=0;
        }
    }
    if(indexutod==-1)
    {
        if(v[0].second<line && v[n-1].second>=line)
        {
            indexutod=0;
        }
    }
    else if(indexdtou==-1)
    {
        if(v[0].second>=line && v[n-1].second<line)
        {
            indexdtou=0;
        }
        else
        {
            if(v[0].second>=line)
            {
                sta=1;
            }
            else
            {
                sta=2;
            }
        }
    }
    //up to down
    double deltax, deltay;
    pair<double,double> p1=v[(indexutod+n-1)%n];
    pair<double,double> p2=v[indexutod];
    if(p1.second-line==0)
    {
        v1.push_back(p1);
    }
    deltay=(p1.second-line) /(p1.second-p2.second);
    v1.push_back({p1.first-deltay*(p1.first-p2.first), p1.second-deltay*(p1.second-p2.second)});
    
    //down to up
    p1=v[indexdtou];
    p2=v[(indexdtou-1+n)%n];
    if(p1.second==line)
    {
        v1.push_back(p1);
        indexdtou++;

    }
    deltay=(p1.second-line)/(p1.second-p2.second);
    v1.push_back({p1.first-deltay*(p1.first-p2.first), p1.second-deltay*(p1.second-p2.second)});

    for(int i=indexdtou;i<n*2;i++)
    {
        if(i==indexutod || i==indexutod+n) break;
        v1.push_back(v[i%n]);
    }
    if(sta==2)
    {
        cout.precision(16);
        cout<<0;
        return 0;
    }
    else if(sta==1)
    {
        cout.precision(16);
        cout<<shoe(1);
    }
    else
    {
        cout.precision(16);
        cout<<shoe(0);
    }

}