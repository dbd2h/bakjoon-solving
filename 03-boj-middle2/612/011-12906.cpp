#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    map<vector<string>,int> m;
    vector<string> s={};
    int a,b,c;
    a=0;
    b=0;
    c=0;
    for(int i=0;i<3;i++)
    {
        int n;
        cin>>n;
        if(n==0)
        {
            s.push_back("");
            continue;
        }
        string iss;
        cin>>iss;
        s.push_back(iss);
        for(int j=0;j<n;j++)
        {
            if(iss[j]=='A') a++;
            if(iss[j]=='B') b++;
            if(iss[j]=='C') c++;
        }
    }
    m[s]=1;
    queue<pair<vector<string>,int>> q;
    q.push({s,0});
    vector<string> answer;
    string ansA,ansB,ansC;
    for(int i=0;i<a;i++)
    {
        ansA+='A';
    }
    for(int i=0;i<b;i++)
    {
        ansB+='B';
    }
    for(int i=0;i<c;i++)
    {
        ansC+='C';
    }
    answer.push_back(ansA);
    answer.push_back(ansB);
    answer.push_back(ansC);
    while(!q.empty())
    {
        vector<string> curV=q.front().first;
        int c=q.front().second;
        if(curV == answer)
        {
            cout<<c;
            return 0;
        }
        q.pop();
        if(curV[0].size())
        {
            char c1=curV[0][curV[0].size()-1];
            vector<string> vs1,vs2;
            vs1.assign(curV.begin(),curV.end());
            vs1[0]=vs1[0].substr(0,vs1[0].size()-1);
            vs1[1]=vs1[1]+c1;
            if(!m[vs1])
            {
                m[vs1]=1;
                q.push({vs1,c+1});
            }

            vs2.assign(curV.begin(),curV.end());
            vs2[0]=vs2[0].substr(0,vs2[0].size()-1);
            vs2[2]=vs2[2]+c1;
            if(!m[vs2])
            {
                m[vs2]=1;
                q.push({vs2,c+1});
            }
        }
        if(curV[1].size())
        {
            char c1=curV[1][curV[1].size()-1];
            vector<string> vs1,vs2;
            vs1.assign(curV.begin(),curV.end());
            vs1[1]=vs1[1].substr(0,vs1[1].size()-1);
            vs1[0]=vs1[0]+c1;
            if(!m[vs1])
            {
                m[vs1]=1;
                q.push({vs1,c+1});
            }

            vs2.assign(curV.begin(),curV.end());
            vs2[1]=vs2[1].substr(0,vs2[1].size()-1);
            vs2[2]=vs2[2]+c1;
            if(!m[vs2])
            {
                m[vs2]=1;
                q.push({vs2,c+1});
            }
        }
        if(curV[2].size())
        {
            char c1=curV[2][curV[2].size()-1];
            vector<string> vs1,vs2;
            vs1.assign(curV.begin(),curV.end());
            vs1[2]=vs1[2].substr(0,vs1[2].size()-1);
            vs1[0]=vs1[0]+c1;
            if(!m[vs1])
            {
                m[vs1]=1;
                q.push({vs1,c+1});
            }

            vs2.assign(curV.begin(),curV.end());
            vs2[2]=vs2[2].substr(0,vs2[2].size()-1);
            vs2[1]=vs2[1]+c1;
            if(!m[vs2])
            {
                m[vs2]=1;
                q.push({vs2,c+1});
            }
        }
    }
}