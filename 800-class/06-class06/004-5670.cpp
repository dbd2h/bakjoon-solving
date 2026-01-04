#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TRIE
{
    TRIE * alpha[26];
    int nextV=0;
    bool finish=0;

    TRIE()
    {
        for(int i=0;i<26;i++)
        {
            alpha[i]=NULL;
        }
    }
    ~TRIE()
    {
        for(int i=0;i<26;i++)
        {
            if(alpha[i]) delete alpha[i];
        }
    }
    void insert(string &s, int idx)
    {
        int len=s.size();
        if(len==idx)
        {
            finish=true;
            return;
        } 
        int cur=s[idx]-'a';
        if(alpha[cur]==NULL)
        {
            alpha[cur] = new TRIE();
            nextV++;
        } 
        alpha[cur]->insert(s,idx+1);
    }
};

void problem(int n)
{
    TRIE * Root = new TRIE();
    vector<string> v;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        v.push_back(s);
        Root->insert(s,0);
    }
    int sumV=0;
    for(int i=0;i<n;i++)
    {
        string s=v[i];
        TRIE * cur=Root;
        int len=s.size();
        for(int j=0;j<len;j++)
        {
            int idx=s[j]-'a';
            if(j==0 || cur->nextV>1 || cur->finish) sumV++;
            cur=cur->alpha[idx];
        }
    }
    cout<<fixed;
    cout.precision(2);
    cout<<double(sumV)/double(n)<<"\n";
    delete Root;
}

int main()
{
    int n;
    while(cin>>n)
    {   
        problem(n);
    }
}