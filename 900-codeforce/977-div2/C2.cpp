#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int test=0;test<t;test++)
    {
        int n,m,q;
        cin>>n>>m>>q;
        int a[200001]={0};
        int b[200001]={0};
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=m;i++) cin>>b[i];
        int si,ti;
        si=0;
        ti=0;
        int savea[200002]={0};
        savea[1]=1;
        int saveb=1;
        for(int update=0;update<q+1;update++)
        {
            if(update!=q) cin>>si>>ti;
            int bit[200001]={0};
            for(int j=1;j<savea[saveb];j++)
            {
                bit[a[j]]=1;
            }
            int ai=savea[saveb];
            int i=saveb;
            for(;i<=m;i++)
            {
                int anum,bnum;
                anum=a[ai];
                bnum=b[i];
                savea[i]=ai;
                if(bit[bnum]==0 && anum!=bnum) break;
                else if(bit[bnum]==0 && anum==bnum)
                {
                    
                    bit[bnum]=1;
                    ai++;
                }
                if(ai>n) break;
            }
            if(si<i) saveb=si;
            if(ai>n || i>m) cout<<"YA\n";
            else cout<<"TIDAK\n";
            if(update==q) break;
            b[si]=ti;
        }
    }
}