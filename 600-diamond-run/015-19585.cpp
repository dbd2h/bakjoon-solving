#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string,bool> teamMap;

struct TRIE
{
    TRIE *NODE[26];
    bool finish;

    TRIE()
    {
        for(int i=0;i<26;i++) NODE[i]=NULL;
        finish=false;
    }
    void insert(int idx, string &s)
    {
        int len=s.size();
        if(idx==len)
        {
            finish=true;
            return;
        }
        int cur=s[idx]-'a';
        if(NODE[cur]==NULL) NODE[cur]=new TRIE();
        NODE[cur]->insert(idx+1,s);
    }
    bool prize(int idx, string &s)
    {
        int len=s.size();
        if(idx==len) return false;
        if(finish && teamMap[s.substr(idx)]) return true;
        int cur=s[idx]-'a';
        if(NODE[cur]==NULL)
        {
            return false;
        } 
        return NODE[cur]->prize(idx+1,s);
    }
};

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int c,n;
    cin>>c>>n;
    TRIE *Root = new TRIE();
    for(int i=0;i<c;i++)
    {
        string s;
        cin>>s;
        Root->insert(0,s);
    }
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        teamMap[s]=true;
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        string s;
        cin>>s;
        if(Root->prize(0,s)) cout<<"Yes\n";
        else cout<<"No\n";
    }
}