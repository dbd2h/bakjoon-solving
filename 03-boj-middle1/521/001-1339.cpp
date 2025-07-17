#include <iostream>
#include <string>

using namespace std;

int power(int n, int s)
{
    if(s==0)
    {
        return 1;
    }
    return power(n,s-1)*n; 
}

void bf(int alpha[], int usedAlpha[], int check[], string input[], int noa, int n, int cur, int *max)
{
    if(cur==noa)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            string s=input[i];
            int len=s.size();
            for(int j=0;j<len;j++)
            {
                int index=s[j]-'A';
                sum+=power(10, len-j-1)*alpha[index];
            }
        }
        if((*max)<sum)
        {
            *max = sum;
        }
        return;
    }
    for(int i=0;i<10;i++)
    {
        int index=usedAlpha[cur];
        if(check[i]==1)
        {
            continue;
        }
        alpha[index]=i;
        check[i]=1;
        bf(alpha, usedAlpha, check, input, noa, n, cur+1, max);
        check[i]=0;
    }
}

int main()
{
    int alpha[26]={0};
    int usedAlpha[10]={0};
    int check[10]={0};
    int noa=0;
    int max=0;
    for(int i=0;i<10;i++)
    {
        usedAlpha[i]=-1;
    }
    int n;
    cin>>n;
    string input[10];
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        input[i]=s;
        int j=0;
        for(int j=0;j<s.size();j++)
        {
            if(alpha[s[j]-'A']==0)
            {
                alpha[s[j]-'A']=1;
                usedAlpha[noa]=s[j]-'A';
                noa++;
            }
        }
    }
    bf(alpha, usedAlpha, check, input, noa, n, 0, &max);
    cout<<max;
}