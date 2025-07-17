#include <iostream>
#include <queue>

using namespace std;

int bit[201]={0};

int water[201][201][201]={0};

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},c});
    water[0][0][c]=1;
    bit[c]=1;
    while(!q.empty())
    {
        int wa,wb,wc;
        wa=q.front().first.first;
        wb=q.front().first.second;
        wc=q.front().second;
        q.pop();
        int la,lb,lc;
        // c->a
        if(wa+wc>a)
        {
            la=a;
            lb=wb;
            lc=wa+wc-a;
            if(!water[la][lb][lc])
            {
                q.push({{la,lb},lc});
                water[la][lb][lc]=1;
                if(la==0)
                {
                    bit[lc]=1;
                }
            }
        }
        else
        {
            la=wa+wc;
            lb=wb;
            lc=0;
            if(!water[la][lb][lc])
            {
                q.push({{la,lb},lc});
                water[la][lb][lc]=1;
                if(la==0)
                {
                    bit[lc]=1;
                }
            }
        }
        // c->b
        if(wb+wc>b)
        {
            la=wa;
            lb=b;
            lc=wb+wc-b;
            if(!water[la][lb][lc])
            {
                q.push({{la,lb},lc});
                water[la][lb][lc]=1;
                if(la==0)
                {
                    bit[lc]=1;
                }
            }
        }
        else
        {
            la=wa;
            lb=wb+wc;
            lc=0;
            if(!water[la][lb][lc])
            {
                q.push({{la,lb},lc});
                water[la][lb][lc]=1;
                if(la==0)
                {
                    bit[lc]=1;
                }
            }
        }
        // a->b
        if(wa+wb>b)
        {
            la=wa+wb-b;
            lb=b;
            lc=wc;
            if(!water[la][lb][lc])
            {
                q.push({{la,lb},lc});
                water[la][lb][lc]=1;
                if(la==0)
                {
                    bit[lc]=1;
                }
            }
        }
        else
        {
            la=0;
            lb=wa+wb;
            lc=wc;
            if(!water[la][lb][lc])
            {
                q.push({{la,lb},lc});
                water[la][lb][lc]=1;
                if(la==0)
                {
                    bit[lc]=1;
                }
            }
        }
        // a->c
        if(wa+wc>c)
        {
            la=wa+wc-c;
            lb=wb;
            lc=c;
            if(!water[la][lb][lc])
            {
                q.push({{la,lb},lc});
                water[la][lb][lc]=1;
                if(la==0)
                {
                    bit[lc]=1;
                }
            }
        }
        else
        {
            la=0;
            lb=wb;
            lc=wa+wc;
            if(!water[la][lb][lc])
            {
                q.push({{la,lb},lc});
                water[la][lb][lc]=1;
                if(la==0)
                {
                    bit[lc]=1;
                }
            }
        }
        // b->a
        if(wa+wb>a)
        {
            la=a;
            lb=wa+wb-a;
            lc=wc;
            if(!water[la][lb][lc])
            {
                q.push({{la,lb},lc});
                water[la][lb][lc]=1;
                if(la==0)
                {
                    bit[lc]=1;
                }
            }
        }
        else
        {
            la=wa+wb;
            lb=0;
            lc=wc;
            if(!water[la][lb][lc])
            {
                q.push({{la,lb},lc});
                water[la][lb][lc]=1;
                if(la==0)
                {
                    bit[lc]=1;
                }
            }
        }
        // b->c
        if(wb+wc>c)
        {
            la=wa;
            lb=wb+wc-c;
            lc=c;
            if(!water[la][lb][lc])
            {
                q.push({{la,lb},lc});
                water[la][lb][lc]=1;
                if(la==0)
                {
                    bit[lc]=1;
                }
            }
        }
        else
        {
            la=wa;
            lb=0;
            lc=wb+wc;
            if(!water[la][lb][lc])
            {
                q.push({{la,lb},lc});
                water[la][lb][lc]=1;
                if(la==0)
                {
                    bit[lc]=1;
                }
            }
        }
    }
    for(int i=0;i<201;i++)
    {
        if(bit[i]) cout<<i<<" ";
    }
}