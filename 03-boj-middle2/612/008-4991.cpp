#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int cross[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
vector<int> v;

int isFinish=0;

bool bfs(int h, int w, int x, int y, int arr[20][20], int bit[11][11], int num, int trashC)
{
    int check[20][20]={0};
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},0});
    int findC=trashC-num;
    while(!q.empty())
    {
        x=q.front().first.first;
        y=q.front().first.second;
        int c=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xp=x+cross[i][0];
            int yp=y+cross[i][1];
            if(xp<0 || xp>=h || yp<0 || yp>=w) continue;
            if(check[xp][yp]==1) continue;
            if(arr[xp][yp]==-1) continue;
            check[xp][yp]=1;
            q.push({{xp,yp},c+1});
            if(arr[xp][yp]!=0)
            {
                bit[num][arr[xp][yp]]=c+1;
                bit[arr[xp][yp]][num]=c+1;
                findC--;
            }
        }
        if(findC==0)
        {
            return true;
        }
    }
    return false;
}

void dfs(int trashC, int bit[11][11], int sum, int *minV, int used[11], int cur, int c)
{
    if(c==trashC)
    {
        if(sum<*minV) *minV = sum;
        return;
    }
    for(int i=1;i<=trashC;i++)
    {
        if(used[i]==1) continue;
        used[i]=1;
        dfs(trashC,bit,sum+bit[cur][i],minV,used,i,c+1);
        used[i]=0;
    }
}

void robot()
{
    int bit[11][11]={0};

    int arr[20][20]={0};

    int trash[11][2]={0};
    int w,h;
    cin>>w>>h;
    if(w==0 && h==0)
    {
        isFinish=1;
        return;
    }
    int trashC=0;
    int x,y;
    for(int i=0;i<h;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<w;j++)
        {
            if(s[j]=='x') arr[i][j]=-1;
            else if(s[j]=='*')
            {
                trashC++;
                arr[i][j]=trashC;
                trash[trashC][0]=i;
                trash[trashC][1]=j;
            }
            else if(s[j]=='o')
            {
                trash[0][0]=i;
                trash[0][1]=j;
            }
        }
    }
    
    if(trashC==0)
    {
        v.push_back(0);
        return;
    }

    for(int i=0;i<trashC;i++)
    {
        x=trash[i][0];
        y=trash[i][1];
        arr[x][y]=0;
        if(!bfs(h,w,x,y,arr,bit,i,trashC))
        {
            v.push_back(-1);
            return;
        }
    }
    int used[11]={0};
    used[0]=1;
    int minV=100000000;
    dfs(trashC,bit,0,&minV,used,0,0);
    v.push_back(minV);
}


int main()
{
    while(true)
    {
        robot();
        if(isFinish) break;
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<"\n";
    }
}