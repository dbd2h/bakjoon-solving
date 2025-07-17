#include <iostream>
#include <string>
#include <stack>

using namespace std;

int bit[10]={0};
int num[11]={0};
char oper[10];
long long maxV=-100000000000;

void comb(int n, int c)
{
    if(n<=c)
    {
        int num1[11]={0};
        char oper1[9];
        int countN=0;
        int countO=0;
        for(int i=0;i<n;i++)
        {
            if(bit[i]==1)
            {
                if(oper[i]=='+')
                {
                    num1[countN]=num[i]+num[i+1];
                }
                if(oper[i]=='-')
                {
                    num1[countN]=num[i]-num[i+1];
                }
                if(oper[i]=='*')
                {
                    num1[countN]=num[i]*num[i+1];
                }
                countN++;
                i++;
                if(i!=n)
                {
                    oper1[countO]=oper[i];
                    countO++;
                }
                continue;
            }
            num1[countN]=num[i];
            countN++;
            oper1[countO]=oper[i];
            countO++;
        }
        if(bit[n-1]==0)
        {
            num1[countN]=num[n];
            countN++;
        }
        stack<int> numS;
        stack<int> operS;
        numS.push(num1[0]);
        for(int i=0;i<countO;i++)
        {
            int n=num1[i+1];
            int o;
            if(oper1[i]=='+') o=1;
            else if(oper1[i]=='-') o=-1;
            else if(oper1[i]=='*') o=0;
            if(o==0)
            {
                int n1=numS.top();
                numS.pop();
                numS.push(n1*n);
            }
            else if(operS.empty())
            {
                numS.push(n);
                operS.push(o);
            }
            else
            {
                int n2=numS.top();
                numS.pop();
                int n1=numS.top();
                numS.pop();
                if(operS.top()==1)
                {
                    numS.push(n1+n2);
                }
                else if(operS.top()==-1)
                {
                    numS.push(n1-n2);
                }
                operS.pop();
                operS.push(o);
                numS.push(n);
            }
        }
        if(!operS.empty())
        {
            int n2=numS.top();
            numS.pop();
            int n1=numS.top();
            numS.pop();
            if(operS.top()==1)
            {
                numS.push(n1+n2);
            }
            else if(operS.top()==-1)
            {
                numS.push(n1-n2);
            }
            operS.pop();
        }
        int n=numS.top();
        numS.pop();
        if(n>maxV) maxV=n;
        return;
    }
    bit[c]=1;
    comb(n,c+2);
    bit[c]=0;
    comb(n,c+1);
}

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            num[i/2]=s[i]-'0';
            continue;
        }
        oper[i/2]=s[i];
    }
    comb(n/2,0);
    cout<<maxV;
}