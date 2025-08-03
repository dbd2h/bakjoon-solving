#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct TRIE
{
    bool finish;
    TRIE*NUMBER[10];
    TRIE()
    {
        finish=false;
        for(int i=0;i<10;i++)
        {
            NUMBER[i]=NULL;
        }
    }
    ~TRIE()
    {
        for(int i=0;i<10;i++)
        {
            if(NUMBER[i]) delete NUMBER[i];
        }
    }
    bool insert(string s, int idx)
    {

        int slen=s.size();
        if(slen==idx)
        {
            finish=true;
            return true;
        }
        if(finish) return false;
        int cur=s[idx]-'0';
        if(!NUMBER[cur]) NUMBER[cur]=new TRIE();
        return NUMBER[cur]->insert(s,idx+1);
    }
};

bool compare(string s1, string s2)
{
    return (s1.size()<s2.size());
}

void telephone()
{
    int n;
    cin>>n;
    vector<string> v;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end(),compare);
    TRIE *Root=new TRIE();
    bool isFinish=false;
    for(int i=0;i<n;i++)
    {
        if(!Root->insert(v[i],0))
        {
            isFinish=true;
            break;
        }
    }
    if(isFinish) cout<<"NO\n";
    else cout<<"YES\n";
    delete Root;
    return;
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        telephone();
    }
}