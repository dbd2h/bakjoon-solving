#include <iostream>
#include <queue>

using namespace std;

int eratos[10000]={0};
int tens[4]={1000,100,10,1};

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    eratos[1]=-1;
    for(int i=2;i<5000;i++)
    {
        if(eratos[i]==-1) continue;
        int mul=2;
        while(i*mul<10000)
        {
            eratos[i*mul]=-1;
            mul++;
        }
    }
    for(int i=0;i<1000;i++)
    {
        eratos[i]=-1;
    }

    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int eratosCopy[10000]={0};
        for(int j=0;j<10000;j++)
        {
            eratosCopy[j]=eratos[j];
        }
        int start, finish;
        cin>>start>>finish;
        queue<int> q;
        queue<int> countQ;
        int val=-1;
        q.push(start);
        countQ.push(0);
        eratosCopy[start]=1;
        while(!q.empty())
        {
            int num=q.front();
            int c=countQ.front();
            if(num==finish)
            {
                val=c;
                break;
            }
            q.pop();
            countQ.pop();
            for(int digit=0;digit<4;digit++)
            {
                int d=(num%(tens[digit]*10))/tens[digit]*tens[digit];
                for(int j=0;j<10;j++)
                {
                    int p=(d+tens[digit]*j)%(tens[digit]*10);
                    int n=num-d+p;
                    if(eratosCopy[n]!=0) continue;
                    q.push(n);
                    countQ.push(c+1);
                    eratosCopy[n]=1;
                }
            }
        }
        if(eratosCopy[finish]==0) cout<<"Impossible"<<"\n";
        else cout<<val<<"\n";
    }
}