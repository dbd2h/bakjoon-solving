#include <iostream>

using namespace std;

struct TRIE
{
    int count;
    TRIE *BIT[2];
    TRIE()
    {
        for(int i=0;i<2;i++) BIT[i]=NULL;
        count=0;
    }
    void insert(int idx, string &s)
    {
        if(idx==s.size()) return;
        int cur=s[idx]-'0';
        if(BIT[cur]==NULL) BIT[cur]= new TRIE();
        BIT[cur]->count++;
        BIT[cur]->insert(idx+1,s);
    }
    void deleteNum(int idx, string &s)
    {
        if(idx==s.size()) return;
        int cur=s[idx]-'0';
        BIT[cur]->count--;
        BIT[cur]->deleteNum(idx+1,s);
    }
    int resMaker(int idx, string &s, int tot)
    {
        if(idx==s.size()) return tot;
        int cur=s[idx]-'0';
        if(BIT[!cur]!=NULL && BIT[!cur]->count!=0) return BIT[!cur]->resMaker(idx+1,s,tot*2+1);
        else return BIT[cur]->resMaker(idx+1,s,tot*2);
    }
};

string bitMaker(int num, int c)
{
    if(c==31)
    {
        return "0";
    }
    int rem=num%2;
    string curS=bitMaker(num/2,c+1);
    if(rem==1) return curS+"1";
    else return curS+"0";
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    TRIE *Root = new TRIE();
    string initNum=bitMaker(0,0);
    Root->insert(0,initNum);
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        string s=bitMaker(b,0);
        if(a==1) Root->insert(0,s);
        else if(a==2) Root->deleteNum(0,s);
        else if(a==3) cout<<Root->resMaker(0,s,0)<<"\n";
    }
}