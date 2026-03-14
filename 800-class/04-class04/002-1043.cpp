#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int tNum;
    cin>>tNum;
    bool tArr[51]={0};
    bool check[50]={0};
    vector<int> partyV[50];
    for(int i=0;i<tNum;i++)
    {
        int num;
        cin>>num;
        tArr[num]=1;
    }
    for(int i=0;i<m;i++)
    {
        int pNum;
        cin>>pNum;
        for(int j=0;j<pNum;j++)
        {
            int num;
            cin>>num;
            partyV[i].push_back(num);
        }
    }
    int befRes=m;
    int curRes=m;
    while(true)
    {
        for(int i=0;i<m;i++)
        {
            if(check[i]) continue;
            bool isF=false;
            for (auto& p : partyV[i])
            {
                if(tArr[p])
                {
                    isF=true;
                    break;
                }
            }
            if(isF)
            {
                check[i]=1;
                for(auto& p : partyV[i])
                {
                    tArr[p]=1;
                }
                curRes--;
            }
        }
        if(befRes==curRes) break;
        befRes=curRes;
    }
    cout<<curRes;
}