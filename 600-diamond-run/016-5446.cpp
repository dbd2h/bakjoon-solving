#include <iostream>

using namespace std;

int indexMaker(char c)
{
    int idx=0;
    if(c-'a'>=0 && c-'a'<26) idx=c-'a';
    else if(c-'A'>=0 && c-'A'<26) idx=c-'A'+26;
    else if(c-'0'>=0 && c-'0'<10) idx=c-'0'+52;
    else idx=62;
    return idx;
}

struct TRIE
{
    TRIE *NODE[63];
    bool isP;
    bool finish;

    TRIE()
    {
        for(int i=0;i<63;i++) NODE[i]=NULL;
        isP=true;
        finish=false;
    }
    ~TRIE()
    {
        for(int i=0;i<63;i++) delete NODE[i];
    }
    void insert(int idx, string &s)
    {
        int len=s.size();
        if(len==idx)
        {
            finish=true;
            return;
        }
        int cur=indexMaker(s[idx]);
        if(NODE[cur]==NULL) NODE[cur]=new TRIE();
        NODE[cur]->insert(idx+1,s);
    }
    void noRemove(int idx, string &s)
    {
        isP=false;
        int len=s.size();
        if(len==idx) return;
        int cur=indexMaker(s[idx]);
        if(NODE[cur]==NULL) return;
        NODE[cur]->noRemove(idx+1,s);
    }
    int deleteF()
    {
        if(isP) return 1;
        int outputV=0;
        for(int i=0;i<63;i++)
        {
            if(NODE[i]==NULL) continue;
            outputV+=NODE[i]->deleteF();
        }
        if(finish) outputV++;
        return outputV;
    }
};

void problem()
{
    int n1;
    cin>>n1;
    TRIE *Root=new TRIE();
    for(int i=0;i<n1;i++)
    {
        string s;
        cin>>s;
        Root->insert(0,s);
    }
    int n2;
    cin>>n2;
    for(int i=0;i<n2;i++)
    {
        string s;
        cin>>s;
        Root->noRemove(0,s);
    }
    int res=Root->deleteF();
    cout<<res<<"\n";
    delete Root;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int i=0;i<t;i++) problem();
}