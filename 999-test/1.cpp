#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

struct TRIE
{
    bool finish;
    int prefix;
    vector<pair<int,TRIE*>> NODE;
    TRIE *FAIL;
    int order;
    TRIE()
    {
        finish=false;
        prefix=-1;
        order=0;
        FAIL=NULL;
    }
    ~TRIE()
    {
        int NODELEN=NODE.size();
        for(int i=0;i<NODELEN;i++)
        {
            delete NODE[i].second;
        }
    }
    void insert(string s, int idx)
    {
        order=idx;
        if(s.size()==idx)
        {
            finish=true;
            prefix=idx;
            return;
        }
        int cur=s[idx]-'a';
        int nodelen=NODE.size();
        int flag=-1;
        for(int i=0;i<nodelen;i++)
        {
            if(NODE[i].first==cur)
            {
                flag=i;
                break;
            }
        }
        if(flag==-1)
        {
            NODE.push_back({cur,new TRIE()});
            NODE[nodelen].second->insert(s,idx+1);
        }
        else
        {
            NODE[flag].second->insert(s,idx+1);
        }
        
    }
};

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string asciS;
    cin>>asciS;
    int m;
    cin>>m;
    TRIE *Root=new TRIE();
    for(int i=0;i<m;i++)
    {
        string s;
        cin>>s;
        Root->insert(s,0);
    }
    queue<TRIE*> q;
    q.push(Root);
    while(!q.empty())
    {
        TRIE *N=q.front();
        q.pop();
        if(N==Root) N->FAIL=Root;
        int nodelen=N->NODE.size();
        for(int i=0;i<nodelen;i++)
        {
            int nextI=N->NODE[i].first;
            TRIE *next=N->NODE[i].second;
            if(N==Root) next->FAIL=Root;
            else
            {
                TRIE *dest=N->FAIL;
                int flag=-1;
                

                while(dest!=Root)
                {
                    int destlen=dest->NODE.size();
                    for(int j=0;j<destlen;j++)
                    {
                        if(dest->NODE[j].first==nextI)
                        {
                            flag=j;
                            break;
                        }
                    }
                    if(flag!=-1)
                    {
                        break;
                    }
                    dest=dest->FAIL;
                }
                int destlen=dest->NODE.size();
                if(dest==Root)
                {
                    for(int j=0;j<destlen;j++)
                    {
                        if(dest->NODE[j].first==nextI)
                        {
                            flag=j;
                            break;
                        }
                    }
                }
                if(flag!=-1) dest=dest->NODE[flag].second;
                next->FAIL=dest;
                if(next->FAIL->prefix>0)
                {
                    if(next->prefix==-1 || next->FAIL->prefix>next->prefix)
                    {
                        next->prefix=next->FAIL->prefix;
                    }
                }
            }
            q.push(next);
        }
    }
    
    int i=0;
    int result=0;
    TRIE *N=Root;
    int arr[300000]={0};
    
    while(i<n)
    {   
        int cur=asciS[i]-'a';
        int nlen=N->NODE.size();
        int flag=-1;
        for(int j=0;j<nlen;j++)
        {
            if(N->NODE[j].first==cur)
            {
                flag=j;
                break;
            }
        }
        if(flag!=-1)
        {
            N=N->NODE[flag].second;
            if(N->prefix>0)
            {
                arr[i]=N->prefix;
            }
            i++;
        }
        else if(N!=Root)
        {
            N=N->FAIL;
        }
        else
        {
            i++;
        }
    }
    int life=0;
    int res=0;
    for(int j=n-1;j>=0;j--)
    {
        if(arr[j]>0 && life<arr[j]) life=arr[j];
        if(life) life--;
        else res++;
    }
    cout<<res;
}