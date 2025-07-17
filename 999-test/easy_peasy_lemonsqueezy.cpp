#include <iostream>
#define MAX_LEN 10000

using namespace std;

int cell[MAX_LEN][MAX_LEN]={0};

int main()
{
    int m,n,swamp;
    cin>>m>>n>>swamp;
    for(int i=0;i<swamp;i++)
    {
        int a,b;
        cin>>a>>b;
        cell[a][b]=-1;
    }
    
}