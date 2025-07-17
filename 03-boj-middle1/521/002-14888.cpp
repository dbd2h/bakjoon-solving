#include <iostream>

#define MAX_LEN 100
#define MAX 1'000'000'001

using namespace std;

void cal(int a[], int oper[], int operOrder[], int n, int cur, int *max, int *min)
{
    if(n-1==cur)
    {
        int result=a[0];
        for(int i=0;i<n-1;i++)
        {
            switch(operOrder[i])
            {
                case 0:
                    result+=a[i+1];
                    break;
                case 1:
                    result-=a[i+1];
                    break;
                case 2:
                    result*=a[i+1];
                    break;
                case 3:
                    result/=a[i+1];
                    break;
            }
        }
        if((*max)<result)
        {
            *max = result;
        }
        if((*min)>result)
        {
            *min = result;
        }
        return;
    }

    for(int i=0;i<4;i++)
    {
        if(oper[i]==0)
        {
            continue;
        }
        oper[i]--;
        operOrder[cur]=i;
        cal(a, oper, operOrder, n, cur+1, max, min);
        oper[i]++;
    }
}

int main()
{
    int n;
    int a[MAX_LEN]={0};
    int oper[4]={0};
    int operOrder[MAX_LEN]={0};

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<4;i++)
    {
        cin>>oper[i];
    }
    int max=-MAX;
    int min=MAX;
    cal(a, oper, operOrder, n, 0, &max, &min);
    cout<<max<<"\n"<<min;
}