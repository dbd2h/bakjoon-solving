#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

int cross[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}};

struct TRIE
{
    TRIE *NODE[26];
    bool finish;
    TRIE()
    {
        for(int i=0;i<26;i++)
        {
            NODE[i]=NULL;
        }
        finish=false;
    }
    ~TRIE()
    {
        for(int i=0;i<26;i++)
        {
            if(NODE[i]) delete(NODE[i]);
        }
    }
    void insert(string s, int idx)
    {
        if(idx==s.size())
        {
            finish=true;
            return;
        }
        int cur=s[idx]-'A';
        if(!NODE[cur])
        {
            NODE[cur]=new TRIE();
        }
        NODE[cur]->insert(s,idx+1);
    }
};

void dfs(char boggle[4][4],int x, int y, TRIE *N, int check[4][4], int c, map<string,bool> &m, string s, int *result, string &maxS, int *wordC)
{
    if(N->finish && !m[s])
    {
        (*wordC)++;
        m[s]=true;
        int slen=s.size();
        if(slen<=2)
        {
            (*result)+=0;
        }
        else if(slen<=4)
        {
            (*result)+=1;
        }
         else if(slen==5)
        {
            (*result)+=2;
        }
        else if(slen==6)
        {
            (*result)+=3;
        }
        else if(slen==7)
        {
            (*result)+=5;
        }
        else if(slen==8)
        {
            (*result)+=11;
        }
        if(maxS.size()<slen) maxS=s;
        else if(maxS.size()==slen && maxS>s) maxS=s;
    }
    if(c==8)
    {
        return;
    }
    for(int i=0;i<8;i++)
    {
        int xp=x+cross[i][0];
        int yp=y+cross[i][1];
        if(xp<0 || xp>=4 || yp<0 || yp>=4) continue;
        if(check[xp][yp]) continue;
        char alpha=boggle[xp][yp];
        if(N->NODE[alpha-'A']==NULL) continue;
        check[xp][yp]=1;
        dfs(boggle,xp,yp,N->NODE[alpha-'A'],check,c+1,m,s+alpha,result,maxS,wordC);
        check[xp][yp]=0;
    }
}

void boggleMaker(TRIE * Root)
{
    char boggle[4][4];
    for(int i=0;i<4;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<4;j++)
        {
            boggle[i][j]=s[j];
        }
    }
    int result=0;
    string maxS;
    int wordC=0;
    map<string,bool> m;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            char first=boggle[i][j];
            if(Root->NODE[first-'A']==NULL) continue;
            string s="";
            s+=first;
            int check[4][4]={0};
            check[i][j]=1;
            
            
            dfs(boggle,i,j,Root->NODE[first-'A'],check,1,m,s,&result,maxS,&wordC);
            
        }
    }
    cout<<result<<" "<<maxS<<" "<<wordC<<"\n";
}

int main()
{
    int w;
    cin>>w;
    TRIE *Root=new TRIE();
    for(int i=0;i<w;i++)
    {
        string s;
        cin>>s;
        Root->insert(s,0);
    }
    int b;
    cin>>b;
    for(int i=0;i<b;i++)
    {
        boggleMaker(Root);
    }
}