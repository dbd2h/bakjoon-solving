#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int prep[1000001]={0};
    string t,p;
    getline(cin,t);
    getline(cin,p);
    int tsize=t.size();
    int psize=p.size();
    int i=0;
    int j=1;
    while(j<psize)
    {
        if(p[i]==p[j])
        {
            prep[j]=++i;
            j++;
        }
        else if(i!=0)
        {
            i=prep[i-1];
        }
        else
        {
            prep[j]=0;
            j++;
        }
    }
    int index=0;
    vector<int> v;
    for(int i=0;i<=tsize;i++)
    {
        if(index==psize)
        {
            v.push_back(i-psize+1);
            index=prep[index-1];
        }
        if(i==tsize) break;
        if(t[i]==p[index])
        {
            index++;
        }
        else
        {
            while(true)
            {
                if(index==0) break;
                index=prep[index-1];
                if(t[i]==p[index])
                {
                    index++;
                    break;
                }
            }
        }
    }
    cout<<v.size()<<"\n";
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i];
        if(i==v.size()-1)
        {
            break;
        }
        cout<<" ";
    }
}    