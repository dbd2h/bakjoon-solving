#include <iostream>
#include <vector>

using namespace std;

void makeV(vector<vector<int>> v[], vector<int> ten, vector<int> cur, int c, int t, int tot)
{
    if(c==11)
    {
        if(t==0 || t>=tot/2) return;
        v[t].push_back(cur);
        return;
    }
    for(int i=0;i<=ten[c];i++)
    {
        cur[c]=i;
        makeV(v,ten,cur,c+1,t+c*i,tot);
    }
}

bool isCor(vector<int> &ten, vector<int> &cur)
{
    for(int i=1;i<=10;i++)
    {
        if(ten[i]<cur[i]) return false;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    vector<int> ten(11);
    int tot=0;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        ten[num]++;
        tot+=num;
    }
    vector<vector<int>> v[80];
    vector<int> cur(11);
    makeV(v,ten,cur,1,0,tot);
    int res=-1;
    for(int h=1;h<tot/2;h++)
    {
        int len1=v[h].size();
        for(int i=0;i<len1;i++)
        {
            for(int idx=1;idx<=10;idx++)
            {
                ten[idx]-=v[h][i][idx];
            }
            for(int j=i;j<len1;j++)
            {
                if(!isCor(ten,v[h][j])) continue;
                for(int idx=1;idx<=10;idx++)
                {
                    ten[idx]-=v[h][j][idx];
                }
                for(int w=h;w<tot/2;w++)
                {
                    int len2=v[w].size();
                    for(int k=0;k<len2;k++)
                    {
                        if(!isCor(ten,v[w][k])) continue;
                        for(int idx=1;idx<=10;idx++)
                        {
                            ten[idx]-=v[w][k][idx];
                        }
                        for(int l=k;l<len2;l++)
                        {
                            if(isCor(ten,v[w][l]))
                            {
                                if(res<h*w) res=h*w;
                                break;
                            }
                        }
                        for(int idx=1;idx<=10;idx++)
                        {
                            ten[idx]+=v[w][k][idx];
                        }
                    }
                }
                for(int idx=1;idx<=10;idx++)
                {
                    ten[idx]+=v[h][j][idx];
                }
            }
            for(int idx=1;idx<=10;idx++)
            {
                ten[idx]+=v[h][i][idx];
            }
        }
    }
    cout<<res;
}