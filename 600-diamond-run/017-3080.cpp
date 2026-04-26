#include <iostream>
#include <vector>

typedef long long ll;

#define REM (ll) 1'000'000'007

using namespace std;

ll fac[28];

struct TRIE
{
    vector<pair<char,TRIE*>> NODE;
    bool finish;
    TRIE()
    {
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
        for(auto&next : NODE)
        {
            if(s[idx]==next.first)
            {
                next.second->insert(idx+1,s);
                return;
            }
        }
        TRIE *curT=new TRIE();
        NODE.push_back({s[idx],curT});
        curT->insert(idx+1,s);
    }
    ll resMaker()
    {
        ll len=finish+NODE.size();
        ll tot=fac[len];
        for(auto& next : NODE)
        {
            tot*=next.second->resMaker();
            tot%=REM;
        }
        return tot;
    }
};

int main()
{
    int n;
    cin>>n;
    TRIE *Root=new TRIE();
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        Root->insert(0,s);
    }
    ll res=1;
    ll idx=1;
    fac[0]=1;
    while(idx<=27)
    {
        fac[idx]=fac[idx-1]*idx;
        fac[idx]%=REM;
        idx+=1;
    }
    cout<<Root->resMaker();
}