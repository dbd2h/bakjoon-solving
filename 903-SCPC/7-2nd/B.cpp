#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
typedef long long ll;
typedef long double lld;

using namespace std;

int arr[8][2];
int cArr[8][2];
bool check[8];
int choice[8];
ll res;

void dist(int c)
{
    if(c==8)
    {
        int x[8];
        int y[8];
        for(int i=0;i<8;i++)
        {
            int c=choice[i];
            x[i]=cArr[c][0]-arr[i][0];
            y[i]=cArr[c][1]-arr[i][1];
        }
        sort(x,x+8);
        sort(y,y+8);
        ll sumV=0;
        for(int i=0;i<8;i++)
        {
            sumV+=abs(x[i]-x[3]);
            sumV+=abs(y[i]-y[3]);
        }
        res=min(res,sumV);
        return;
    }
    for(int i=0;i<8;i++)
    {
        if(check[i]) continue;
        check[i]=1;
        choice[c]=i;
        dist(c+1);
        check[i]=0;
    }
}



void program()
{
    int k;
    cin>>k;
    res=(1e10);
    cArr[0][0]=0;
    cArr[0][1]=0;
    cArr[1][0]=0;
    cArr[1][1]=k;
    cArr[2][0]=-k;
    cArr[2][1]=-k;
    cArr[3][0]=-k;
    cArr[3][1]=k*2;
    cArr[4][0]=-k*2;
    cArr[4][1]=-k;
    cArr[5][0]=-k*2;
    cArr[5][1]=k*2;
    cArr[6][0]=-k*3;
    cArr[6][1]=0;
    cArr[7][0]=-k*3;
    cArr[7][1]=k;
    for(int i=0;i<8;i++)
    {
        int x,y;
        cin>>x>>y;
        arr[i][0]=x;
        arr[i][1]=y;
        check[i]=0;
    }
    dist(0);
    cout<<res<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<endl;
        program();
    }
    
}