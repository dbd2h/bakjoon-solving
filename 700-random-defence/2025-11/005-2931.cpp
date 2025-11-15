#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int cross[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

bool canGo(char arr[27][27], pair<int,int> p1, pair<int,int> p2)
{
    int x1=p1.first;
    int y1=p1.second;
    int x2=p2.first;
    int y2=p2.second;
    char cur=arr[x2][y2];
    if(cur=='M' || cur=='Z') return true;
    if(x2-x1==1 && y1==y2)
    {
        if(cur=='|' || cur=='+' || cur=='2' || cur=='3') return true;
        else return false;
    }
    else if(x2-x1==-1 && y1==y2)
    {
        if(cur=='|' || cur=='+' || cur=='1' || cur=='4') return true;
        else return false;
    }
    else if(y2-y1==1 && x1==x2)
    {
        if(cur=='-' || cur=='+' || cur=='3' || cur=='4') return true;
        else return false;
    }
    else if(y2-y1==-1 && x1==x2)
    {
        if(cur=='-' || cur=='+' || cur=='1' || cur=='2') return true;
        else return false;
    }
}

int main()
{
    int r,c;
    cin>>r>>c;
    char arr[27][27];
    pair<int,int> M,Z;
    for(int i=0;i<r;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<c;j++)
        {
            arr[i][j]=s[j];
            if(arr[i][j]=='M') M={i,j};
            if(arr[i][j]=='Z') Z={i,j};
        }
    }
    queue<pair<pair<int,int>,int>> q;
    int isF=true;
    int check[27][27]={0};
    for(int i=0;i<4;i++)
    {
        int xp=M.first+cross[i][0];
        int yp=M.second+cross[i][1];
        if(xp<0 || xp>=r || yp<0 || yp>=c) continue;
        if(arr[xp][yp]=='.') continue;
        if(!canGo(arr,M,{xp,yp})) continue;
        isF=false;
    }
    if(isF)
    {
        for(int i=0;i<4;i++)
        {
            int xp=Z.first+cross[i][0];
            int yp=Z.second+cross[i][1];
            if(xp<0 || xp>=r || yp<0 || yp>=c) continue;
            if(arr[xp][yp]=='.') continue;
            if(!canGo(arr,Z,{xp,yp})) continue;
            isF=false;
        }
        if(isF)
        {
            pair<int,int> point={(M.first+Z.first)/2,(M.second+Z.second)/2};
            if(Z.first==M.first)
            {
                cout<<point.first+1<<" "<<point.second+1<<" "<<'-';
            }
            else if(Z.second==M.second)
            {
                cout<<point.first+1<<" "<<point.second+1<<" "<<'|';
            }
            else
            {
                for(int i=0;i<4;i++)
                {
                    int xp=M.first+cross[i][0];
                    int yp=M.second+cross[i][1];
                    if(xp<0 || xp>=r || yp<0 || yp>=c) continue;
                    if(arr[xp][yp]!='.') continue;
                    bool isF1=false;
                    for(int j=0;j<4;j++)
                    {
                        int xp1=xp+cross[j][0];
                        int yp1=yp+cross[j][1];
                        if(xp1<0 || xp1>=r || yp1<0 || yp1>=c) continue;
                        if(!canGo(arr,{xp,yp},{xp1,yp1}))
                        {
                            isF1=true;
                            break;
                        }
                    }
                    if(isF1) continue;
                    cout<<xp+1<<" "<<yp+1<<" "<<'+';
                    break;
                }
            }
            return 0;
        }
        q.push({Z,-1});
        check[Z.first][Z.second]=1;
    }
    else
    {
        q.push({M,-1});
        check[M.first][M.second]=1;
    } 
    pair<int,int> point={-1,-1};
    while(!q.empty())
    {
        int x=q.front().first.first;
        int y=q.front().first.second;
        int bef=q.front().second;
        q.pop();
        char cur=arr[x][y];
        for(int i=0;i<4;i++)
        {
            if(cur=='-' || cur=='|' || cur=='+')
            {
                if(i!=bef) continue;
            }
            else if(cur-'0'>=1 && cur-'0'<=4)
            {
                int num=cur-'0'-1;
                if(i!=num && i!=(num+1)%4) continue;
                int befC=(bef+2)%4;
                if(i==befC) continue;
            }
            int xp=x+cross[i][0];
            int yp=y+cross[i][1];
            if(xp<0 || xp>=r || yp<0 || yp>=c) continue;
            if(arr[xp][yp]!='+' && check[xp][yp]) continue;
            if(arr[xp][yp]=='+' && check[xp][yp]>=2) continue;
            if((cur=='M' || cur=='Z') && arr[xp][yp]=='.') continue;
            if(arr[xp][yp]=='.')
            {
                point={xp,yp};
                break;
            }
            check[xp][yp]++;
            q.push({{xp,yp},i});
        }
        if(point.first!=-1) break;
    }
    bool crossCheck[4]={0};
    int m1=-1,z1=-1;
    int totV=0;
    for(int i=0;i<4;i++)
    {
        int xp=point.first+cross[i][0];
        int yp=point.second+cross[i][1];
        if(xp<0 || xp>=r || yp<0 || yp>=c) continue;
        if(!canGo(arr,point,{xp,yp})) continue;
        if(xp==M.first && yp==M.second) m1=i;
        if(xp==Z.first && yp==Z.second) z1=i;
        crossCheck[i]=1;
        totV++;
    }
    if(totV==3)
    {
        for(int i=0;i<4;i++)
        {
            int xp=point.first+cross[i][0];
            int yp=point.second+cross[i][1];
            if(xp<0 || xp>=r || yp<0 || yp>=c) continue;
            if(arr[xp][yp]=='M' || arr[xp][yp]=='Z') crossCheck[i]=0;
        }
    }
    cout<<point.first+1<<" "<<point.second+1<<" ";
    if(crossCheck[0] && crossCheck[1] && crossCheck[2] && crossCheck[3])
    {
        if((m1==0 && z1==2) || (m1==2 && z1==0)) cout<<'-';
        if((m1==1 && z1==3) || (m1==3 && z1==1)) cout<<'|';
        else cout<<'+';
    }
    else if(crossCheck[0] && crossCheck[2]) cout<<'|';
    else if(crossCheck[1] && crossCheck[3]) cout<<'-';
    else if(crossCheck[0] && crossCheck[1]) cout<<'1';
    else if(crossCheck[1] && crossCheck[2]) cout<<'2';
    else if(crossCheck[2] && crossCheck[3]) cout<<'3';
    else if(crossCheck[3] && crossCheck[0]) cout<<'4';
}