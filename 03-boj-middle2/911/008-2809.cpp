#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


struct TRIE
{
    vector<pair<char,TRIE*>> NODE;
    int prefix;
    TRIE* FAIL;
    TRIE()
    {
        prefix=-1;
        FAIL=NULL;
        NODE.clear();
    }
    void insert(string& s,int idx)
    {
        if(s.size()==idx)
        {
            prefix=idx;
            return;
        }
        for(auto& i : NODE)
        {
            if(i.first==s[idx])
            {
                i.second->insert(s,idx+1);
                return;
            }
        }
        NODE.push_back({s[idx],new TRIE()});
        int nsize=NODE.size();
        NODE[nsize-1].second->insert(s,idx+1);
    }
};

int main()
{
    cin.tie(0); 
    cout.tie(0); 
    ios::sync_with_stdio(false);
    int n;
    string first;
    cin>>n>>first;
    int m;
    cin>>m;
    TRIE* Root=new TRIE();
    for(int i=0;i<m;i++)
    {
        string s;
        cin>>s;
        Root->insert(s,0);
    }
    queue<TRIE*> q;
    q.push(Root);
    Root->FAIL=Root;
    while(!q.empty())
    {
        TRIE *cur=q.front();
        q.pop();
        for(auto& i : cur->NODE)
        {
            TRIE* next=i.second;
            if(cur==Root) next->FAIL=Root;
            else
            {
                TRIE *dest=cur->FAIL;
                while(dest!=Root)
                {
                    bool flag=false;
                    for(auto& j : dest->NODE)
                    {
                        if(j.first==i.first)
                        {
                            flag=true;
                            break;
                        }
                    }
                    if(flag) break;
                    dest=dest->FAIL;
                }
                for(auto& j : dest->NODE)
                {
                    if(j.first==i.first)
                    {
                        dest=j.second;
                    }
                }
                next->FAIL=dest;
            }
            
            if(next->FAIL->prefix>=0)
            {
                if(next->prefix==-1 || next->prefix<next->FAIL->prefix)
                {
                    next->prefix=next->FAIL->prefix;
                }
            }
            q.push(next);
        }
    }

    int i=0;
    TRIE*N=Root;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        while(N!=Root)
        {
            bool flag=false;
            for(auto& j : N->NODE)
            {
                if(j.first==first[i])
                {
                    flag=true;
                    break;
                }
            }
            if(flag) break;
            N=N->FAIL;
        }
        for(auto& j : N->NODE)
        {
            if(j.first==first[i])
            {
                N=j.second;
                break;
            }
        }
        if (N->prefix >= 0) v.push_back({ i - N->prefix + 1, i });
    }
    
    sort(v.begin(),v.end());
    int last=-1;
    int res=0;
    for(int i=0;i<v.size();i++)
    {
        if(last<v[i].first) res+=(v[i].first-last-1);
        last=max(last,v[i].second);
    }
    res+=(first.size()-last-1);
    cout<<res;
}