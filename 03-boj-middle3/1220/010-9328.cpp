#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int cross[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void problem()
{
    int h,w;
    cin>>h>>w;
    vector<pair<int,int>> alpha[26];
    char map[100][100];
    for(int i=0;i<h;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<w;j++)
        {
            map[i][j]=s[j];
            if(s[j]-'A'>=0 && s[j]-'A'<26)
            {
                alpha[s[j]-'A'].push_back({i,j});
            }
        }
    }
    string s;
    cin>>s;
    bool key[26]={0};
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0') break;
        key[s[i]-'a']=1;
    }
    bool check[100][100]={0};
    queue<pair<int,int>> q;
    int res=0;
    for(int i=0;i<h;i++)
    {
        if(map[i][0]!='*' && check[i][0]==0)
        {
            char cur=map[i][0];
            check[i][0]=1;
            if(cur=='.')
            {
                q.push({i,0});
            }
            else if(cur-'a'>=0 && cur-'a'<26)
            {
                q.push({i,0});
                if(key[cur-'a']==0)
                {
                    key[cur-'a']=1;
                    for(auto &p : alpha[cur-'a'])
                    {
                        if(check[p.first][p.second]) q.push(p);
                    }
                }
                
            }
            else if(cur-'A'>=0 && cur-'A'<26)
            {
                if(key[cur-'A']) q.push({i,0});
            }
            else if(cur=='$')
            {
                res++;
                q.push({i,0});
            }
        }
        if(map[i][w-1]!='*' && check[i][w-1]==0)
        {
            char cur=map[i][w-1];
            check[i][w-1]=1;
            if(cur=='.')
            {
                q.push({i,w-1});
                
            }
            else if(cur-'a'>=0 && cur-'a'<26)
            {
                q.push({i,w-1});
                if(key[cur-'a']==0)
                {
                    key[cur-'a']=1;
                    for(auto &p : alpha[cur-'a'])
                    {
                        if(check[p.first][p.second]) q.push(p);
                    }
                }
            }
            else if(cur-'A'>=0 && cur-'A'<26)
            {
                if(key[cur-'A']) q.push({i,w-1});
            }
            else if(cur=='$')
            {
                res++;
                q.push({i,w-1});
            }
        }
    }
    for(int i=0;i<w;i++)
    {
        if(map[0][i]!='*' && check[0][i]==0)
        {
            char cur=map[0][i];
            check[0][i]=1;
            if(cur=='.')
            {
                q.push({0,i});
            }
            else if(cur-'a'>=0 && cur-'a'<26)
            {
                q.push({0,i});
                if(key[cur-'a']==0)
                {
                    key[cur-'a']=1;
                    for(auto &p : alpha[cur-'a'])
                    {
                        if(check[p.first][p.second]) q.push(p);
                    }
                }
            }
            else if(cur-'A'>=0 && cur-'A'<26)
            {
                if(key[cur-'A']) q.push({0,i});
            }
            else if(cur=='$')
            {
                res++;
                q.push({0,i});
            }
        }
        if(map[h-1][i]!='*' && check[h-1][i]==0)
        {
            char cur=map[h-1][i];
            check[h-1][i]=1;
            if(cur=='.')
            {
                q.push({h-1,i});
            }
            else if(cur-'a'>=0 && cur-'a'<26)
            {
                q.push({h-1,i});
                if(key[cur-'a']==0)
                {
                    key[cur-'a']=1;
                    for(auto &p : alpha[cur-'a'])
                    {
                        if(check[p.first][p.second]) q.push(p);
                    }
                }
            }
            else if(cur-'A'>=0 && cur-'A'<26)
            {
                if(key[cur-'A']) q.push({h-1,i});
            }
            else if(cur=='$')
            {
                res++;
                q.push({h-1,i});
            }
        }
    }
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xp=x+cross[i][0];
            int yp=y+cross[i][1];
            if(xp<0 || xp>=h || yp<0 || yp>=w) continue;
            if(check[xp][yp]) continue;
            if(map[xp][yp]=='*') continue;
            check[xp][yp]=1;
            char cur=map[xp][yp];
            if(cur=='.') q.push({xp,yp});
            else if(cur-'a'>=0 && cur-'a'<26)
            {
                q.push({xp,yp});
                if(key[cur-'a']==0)
                {
                    key[cur-'a']=1;
                    for(auto &p : alpha[cur-'a'])
                    {
                        if(check[p.first][p.second]) q.push(p);
                    }
                }
            }
            else if(cur-'A'>=0 && cur-'A'<26)
            {
                if(key[cur-'A']) q.push({xp,yp});
            }
            else if(cur=='$')
            {
                q.push({xp,yp});
                res++;
            }
        }
    }
    cout<<res<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        problem();
    }
}