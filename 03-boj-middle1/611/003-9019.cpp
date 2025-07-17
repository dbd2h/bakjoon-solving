#include <iostream>
#include <queue>
#include <string>

using namespace std;

int calD(int n)
{
    return (n*2)%10000;
}

int calS(int n)
{
    return (n-1+10000)%10000;
}

int calL(int n)
{
    int n1=n/1000;
    return (n%1000)*10+n1;
}

int calR(int n)
{
    int n4=n%10;
    return n4*1000+n/10;
}

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int ite=0;ite<t;ite++)
    {
        int check[10000]={0};
        int num, object;
        cin>>num>>object;
        queue<pair<int,string>> q;
        string s;
        q.push({num, s});
        string result;
        while(!q.empty())
        {
            pair<int,string> p=q.front();
            q.pop();
            int curNum=p.first;
            string curS=p.second;
            if(curNum==object)
            {
                result=curS;
                break;
            }
            int nextNum;
            nextNum=calD(curNum);
            if(check[nextNum]==0)
            {
                check[nextNum]=1;
                q.push({nextNum, curS+'D'});
            }
            nextNum=calS(curNum);
            if(check[nextNum]==0)
            {
                check[nextNum]=1;
                q.push({nextNum, curS+'S'});
            }
            nextNum=calR(curNum);
            if(check[nextNum]==0)
            {
                check[nextNum]=1;
                q.push({nextNum, curS+'R'});
            }
            nextNum=calL(curNum);
            if(check[nextNum]==0)
            {
                check[nextNum]=1;
                q.push({nextNum, curS+'L'});
            }
            
            
        }
        cout<<result<<"\n";
    }
    
}