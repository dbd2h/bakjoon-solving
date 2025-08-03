#include <iostream>

using namespace std;

void backtest(int l, int r, int c, char *result, bool *finish, int inc, int dec, int before, int arr[])
{
    if(l>r)
    {
        *finish=true;
        return;
    }
    if(c!=0)
    {
        //l
        if(before<arr[l] && inc!=4)
        {
            result[c]='L';
            backtest(l+1,r,c+1,result,finish,inc+1,1,arr[l],arr);
            if(*finish) return;
        }
        else if(before>arr[l] && dec!=4)
        {
            result[c]='L';
            backtest(l+1,r,c+1,result,finish,1,dec+1,arr[l],arr);
            if(*finish) return;
        }
        if(before<arr[r] && inc!=4)
        {
            result[c]='R';
            backtest(l,r-1,c+1,result,finish,inc+1,1,arr[r],arr);
            if(*finish) return;
        }
        else if(before>arr[r] && dec!=4)
        {
            result[c]='R';
            backtest(l,r-1,c+1,result,finish,1,dec+1,arr[r],arr);
            if(*finish) return;
        }
        return;
    }
    result[c]='L';
    backtest(l+1,r,c+1,result,finish,1,1,arr[l],arr);
    if(*finish) return;
    result[c]='R';
    backtest(l,r-1,c+1,result,finish,1,1,arr[r],arr);
    if(*finish) return;
}

void dequeProcess()
{
    int n;
    cin>>n;
    int arr[100000]={0};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    char result[100000];
    bool finish=false;
    backtest(0,n-1,0,result,&finish,0,0,0,arr);
    for(int i=0;i<n;i++)
    {
        cout<<result[i];
    }
    cout<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        dequeProcess();
    }
}


