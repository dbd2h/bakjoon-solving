#include <iostream>
#include <string>
#define LEN 20

using namespace std;

struct TRIE
{
    long long SUM;
    TRIE *BIT[2];
    TRIE()
    {
        SUM=0;
        for(int i=0;i<2;i++)
        {
            BIT[i]=NULL;
        }
    }
    ~TRIE()
    {
        for(int i=0;i<2;i++)
        {
            if(BIT[i]) delete BIT[i];
        }
    }
    void insert(string s, int idx)
    {
        if(idx==s.size()) return;
        int cur=s[idx]-'0';
        if(!BIT[cur]) BIT[cur]=new TRIE();
        BIT[cur]->SUM++;
        BIT[cur]->insert(s,idx+1);
    }
};

string bitMaker(long long num)
{
    int c=0;
    string s;
    while(num)
    {
        if(num%2==1)
        {
            s='1'+s;
        }
        else if(num%2==0)
        {
            s='0'+s;
        }
        num/=2;
        c++;
    }
    for(int i=c;i<LEN;i++)
    {
        s='0'+s;
    }
    return s;
}

void xorF(int idx, TRIE*N1, TRIE*N2, long long *result, string bitK)
{
    if(idx==bitK.size()) return;
    if(bitK[idx]=='0')
    {
        if(N1->BIT[0] && N2->BIT[0]) xorF(idx+1,N1->BIT[0],N2->BIT[0],result,bitK);
        if(N1->BIT[1] && N2->BIT[1]) xorF(idx+1,N1->BIT[1],N2->BIT[1],result,bitK);
        return;
    }
    if(N1==N2)
    {
        if(N1->BIT[0]) *result+=(N1->BIT[0]->SUM)*(N1->BIT[0]->SUM-1)/2;
        if(N1->BIT[1]) *result+=(N1->BIT[1]->SUM)*(N1->BIT[1]->SUM-1)/2;
        if(N1->BIT[0] && N1->BIT[1]) xorF(idx+1,N1->BIT[0],N1->BIT[1],result,bitK);
    }
    else
    {
        if(N1->BIT[0] && N2->BIT[0]) *result+=(N1->BIT[0]->SUM)*(N2->BIT[0]->SUM);
        if(N1->BIT[1] && N2->BIT[1]) *result+=(N1->BIT[1]->SUM)*(N2->BIT[1]->SUM);
        if(N1->BIT[0] && N2->BIT[1]) xorF(idx+1,N1->BIT[0],N2->BIT[1],result,bitK);
        if(N1->BIT[1] && N2->BIT[0]) xorF(idx+1,N1->BIT[1],N2->BIT[0],result,bitK);
    }
}

long long numArr[100000]={0};

void brute(long long n, long long k)
{
    long long result=0;
    for(int i=0;i<n;i++)
    {
        int num=0;
        for(int j=i;j<n;j++)
        {
            num=num^numArr[j];
            if(num<k) result++;
        }
    }
    cout<<result<<"\n";
}

int main()
{
    long long n,k;
    cin>>n>>k;
    long long result=0;
    long long xorNum=0;
    TRIE* Root=new TRIE();
    for(int i=0;i<n;i++)
    {
        long long num;
        cin>>num;
        numArr[i]=num;
        xorNum=xorNum^num;
        if(xorNum<k) result++;
        string bitN=bitMaker(xorNum);
        Root->insert(bitN,0);
    }
    TRIE* N=Root;
    string bitK=bitMaker(k);
    xorF(0,Root,Root,&result,bitK);
    //brute(n,k);
    cout<<result;
}