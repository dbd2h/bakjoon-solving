#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

bool compare(string s1, string s2)
{
    return s1.size()<s2.size();
}

struct TRIE
{
    bool finish;
    TRIE *Node[26];
    TRIE *Stop;

    TRIE()
    {
        finish=false;
        memset(Node, 0, sizeof(Node));
        Stop=NULL;
    }
    void insert(string s,int idx)
    {
        if(s.size()==idx)
        {
            finish=true;
            return;
        }
        int cur=s[idx]-'a';
        if(Node[cur]==NULL) Node[cur]= new TRIE();
        Node[cur]->insert(s,idx+1);
    }

    
};

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    TRIE *Root=new TRIE();
    Root->Stop=Root;
    vector<string> v;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        Root->insert(s,0);
    }
    queue<TRIE*> q;
    q.push(Root);
    while(!q.empty())
    {
        TRIE * N=q.front();
        q.pop();
        for(int i=0;i<26;i++)
        {
            TRIE* next=N->Node[i];
            if(next==NULL) continue;
            if(N==Root) next->Stop=Root;
            else
            {
                TRIE * dest=N->Stop;
                while(dest!=Root && !dest->Node[i])
                {
                    dest=dest->Stop;
                }
                if(dest->Node[i]) dest=dest->Node[i];
                next->Stop=dest;
            }
            if(next->Stop->finish) next->finish=true;
            q.push(next);
        }
    }

    int qc;
    cin>>qc;
    for(int i=0;i<qc;i++)
    {
        string s;
        cin>>s;
        bool result=false;
        TRIE* cur=Root;
        int ssize=s.size();
        for(int j=0;j<ssize;j++)
        {
            int next=s[j]-'a';
            while(cur!=Root && !cur->Node[next]) cur=cur->Stop;
            if(cur->Node[next]) cur=cur->Node[next];
            if(cur->finish)
            {
                result=true;
                break;
            }
        }
        if(result==true) cout<<"YES\n";
        else cout<<"NO\n";
    }
}