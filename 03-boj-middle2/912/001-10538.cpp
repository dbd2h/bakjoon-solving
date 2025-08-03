#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <vector>

using namespace std;

struct TRIE
{
    TRIE *BIT[2];
    int end;
    TRIE *FAIL;
    TRIE()
    {
        for(int i=0;i<2;i++) BIT[i]=NULL;
        end=0;
        FAIL=NULL;
    }
    void insert(string &s,int idx, int mv)
    {
        if(s.size()==idx)
        {
            end=mv;
            return;
        }
        int cur = s[idx]=='o' ? 1 : 0;
        if(BIT[cur]==NULL) BIT[cur]=new TRIE();
        BIT[cur]->insert(s,idx+1,mv);
    }
};



int main()
{
    int ph,pw,mh,mw;
    cin>>ph>>pw>>mh>>mw;
    TRIE *Root=new TRIE();
    int arr[2000]={0};
    map<string,int> m;
    int c=0;
    for(int i=0;i<ph;i++)
    {
        string s;
        cin>>s;

        if(!m[s])
        {
            c++;
            arr[i]=c;
            m[s]=c;
        }
        else arr[i]=m[s];
        Root->insert(s,0,arr[i]);
    }

    int sidx=0;
    int aidx=1;
    int kmp[2000]={0};
    while(aidx<ph)
    {
        if(arr[sidx]==arr[aidx])
        {
            kmp[aidx]=++sidx;
            aidx++;
        }
        else if(sidx!=0) sidx=kmp[sidx-1];
        else aidx++;
    }
    
    queue<TRIE*> q;
    Root->FAIL=Root;
    q.push(Root);
    while(!q.empty())
    {
        TRIE*cur=q.front();
        
        q.pop();
        
        for(int i=0;i<2;i++)
        {
            
            if(!cur->BIT[i]) continue;
            TRIE*next=cur->BIT[i];
            
            if(cur==Root) next->FAIL=Root;
            else
            {
                TRIE*dest=cur->FAIL;
                while(dest!=Root)
                {
                    if(dest->BIT[i]) break;
                    dest=dest->FAIL;
                }
                if(dest->BIT[i]) dest=dest->BIT[i];
                next->FAIL=dest;
            }
            q.push(next);
        }
    }
    int pic[2000][2000]={0};

    for(int i=0;i<mh;i++)
    {
        string s;
        cin>>s;
        TRIE*N=Root;
        for(int j=0;j<mw;j++)
        {
            int cur=s[j]=='o'?1:0;
            while(N!=Root && !N->BIT[cur]) N=N->FAIL;
            if(N->BIT[cur]) N=N->BIT[cur];
            if(N->end>0) pic[i][j]=N->end;
        }
    }
    int res=0;
    for(int i=pw-1;i<mw;i++)
    {
        int a=0;
        for(int j=0;j<mh;j++)
        {
            while(a!=0 && pic[j][i]!=arr[a]) a=kmp[a-1];
            if(pic[j][i]==arr[a])
            {
                a++;
                if(a==ph)
                {
                    res++;
                    a=kmp[a-1];
                }
            }
        }
    }
    cout<<res;
}
