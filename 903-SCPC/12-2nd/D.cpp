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
#define LEN 2001

using namespace std;

int check[LEN][LEN][4];
bool arr[LEN][LEN];

void program()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=2000;i++)
    {
        for(int j=0;j<=2000;j++)
        {
            check[i][j][0]=check[i][j][1]=check[i][j][2]=check[i][j][3]=-1;
            arr[i][j]=0;
        }     
    }
    for(int i=0;i<n;i++)
    {
        int x1,x2,y1,y2;
        cin>>x1>>x2>>y1>>y2;
        
    }
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