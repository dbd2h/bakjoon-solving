#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct TRIE
{
    bool finish;
    TRIE* DNA[4]; //A,G,T,C
    TRIE* FAIL;
    TRIE()
    {
        finish=false;
        for(int i=0;i<4;i++)
        {
            DNA[i]=NULL;
        }
        FAIL=NULL;
    }
    ~TRIE()
    {
        for(int i=0;i<4;i++)
        {
            if(DNA[i]) delete(DNA[i]);
        }
    }

    void insert(string s, int idx)
    {
        int ssize=s.size();
        if(idx==ssize)
        {
            finish=true;
            return;
        }
        int cur=0;
        if(s[idx]=='A') cur=0;
        else if(s[idx]=='G') cur=1;
        else if(s[idx]=='T') cur=2;
        else if(s[idx]=='C') cur=3;
        if(DNA[cur]==NULL) DNA[cur]=new TRIE();
        DNA[cur]->insert(s,idx+1);
    }
};

void mutation()
{
    int n,m;
    cin>>n>>m;
    string s1,s2;
    cin>>s1>>s2;
    TRIE * Root=new TRIE();
    TRIE * curTRIE=Root;
    Root->insert(s2,0);
    for(int i=0;i<m;i++)
    {
        for(int j=i+1;j<m;j++)
        {
            string inputS;
            for(int k=j;k>=i;k--)
            {
                inputS+=s2[k];
            }
            inputS+=s2.substr(j+1);
            curTRIE->insert(inputS,0);
        }
        int cur=0;
        if(s2[i]=='A') cur=0;
        else if(s2[i]=='G') cur=1;
        else if(s2[i]=='T') cur=2;
        else if(s2[i]=='C') cur=3;
        curTRIE=curTRIE->DNA[cur];
    }
    Root->FAIL=Root;
    queue<TRIE*> q;
    q.push(Root);
    while(!q.empty())
    {
        TRIE *current=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            TRIE *next=current->DNA[i];
            if(next==NULL) continue;
            if(current==Root) next->FAIL=Root;
            else
            {
                TRIE *dest=current->FAIL;
                while(dest!=Root && dest->DNA[i]==NULL) dest=dest->FAIL;
                if(dest->DNA[i]!=NULL) dest=dest->DNA[i];
                next->FAIL=dest;
            }
            q.push(next);
        }
    }

    int slen=s1.size();
    TRIE* curN=Root;
    int result=0;
    for(int i=0;i<slen;i++)
    {
        int cur=0;
        if(s1[i]=='A') cur=0;
        else if(s1[i]=='G') cur=1;
        else if(s1[i]=='T') cur=2;
        else if(s1[i]=='C') cur=3;
        while(curN!=Root && curN->DNA[cur]==NULL) curN=curN->FAIL;
        if(curN->DNA[cur]!=NULL) curN=curN->DNA[cur];
        if(curN->finish)
        {
            result++;
            curN=curN->FAIL;
        }
    }
    cout<<result<<"\n";
    delete Root;
    return;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        mutation();
    }
    return 0;
}