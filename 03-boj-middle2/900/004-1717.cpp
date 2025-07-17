#include <iostream>

using namespace std;

int tree[1000002]={0};

void rootF(int a, int b, int *ar, int *br)
{
    int treea=tree[a];
    int treeb=tree[b];
    int ca=a;
    int cb=b;
    while(tree[a]!=0)
    {
        a=tree[a];
    }
    *ar=a;
    a=ca;
    while(a!= *ar)
    {
        tree[a]= *ar;
        a=treea;
        treea=tree[a];
    }
    while(tree[b]!=0)
    {
        b=tree[b];
    }
    *br=b;
    b=cb;
    while(b!= *br)
    {
        tree[b]= *br;
        b=treeb;
        treeb=tree[b];
    }
}

void unionF(int a, int b)
{
    if(a==b) return;
    int ar,br;
    rootF(a,b,&ar,&br);
    if(ar==br) return;
    if(ar<br)
    {
        int treeb=tree[b];
        int treea=tree[a];
        while(b!=0)
        {
            tree[b]=ar;
            b=treeb;
            treeb=tree[b];
        }
        while(a!=ar)
        {
            tree[a]=ar;
            a=treea;
            treea=tree[a];
        }
    }
    else if(ar>br)
    {
        int treea=tree[a];
        int treeb=tree[b];
        while(a!=0)
        {
            tree[a]=br;
            a=treea;
            treea=tree[a];
        }
        while(b!=br)
        {
            tree[b]=br;
            b=treeb;
            treeb=tree[b];
        }
    }
}



int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    int s,a,b;
    for(int i=0;i<m;i++)
    {
        cin>>s>>a>>b;
        a++;
        b++;
        if(s==0)
        {
            unionF(a,b);
        }
        else if(s==1)
        {
            int ar,br;
            rootF(a,b,&ar,&br);
            if(ar==br) cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
        }
    }
}