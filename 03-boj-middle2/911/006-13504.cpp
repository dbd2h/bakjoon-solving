#include <iostream>
#include <queue>

using namespace std;

struct TRIE
{
    bool finish;
    TRIE*BIT[2];
    TRIE()
    {
        finish=false;
        for(int i=0;i<2;i++)
        {
            BIT[i]=NULL;
        }
    }
    ~TRIE()
    {
        for(int i=0;i<2;i++)
        {
            delete BIT[i];
        }
    }
    void insert(string s, int idx)
    {
        if(s.size()==idx)
        {
            finish=true;
            return;
        }
        int cur=s[idx]-'0';
        if(!BIT[cur]) BIT[cur]=new TRIE();
        BIT[cur]->insert(s,idx+1);
    }
};

string bitMaker(int num)
{
    string s;
    while(num)
    {
        if(num%2==1)
        {
            s='1'+s;
        }
        else
        {
            s='0'+s;
        }
        num/=2;
    }
    int slen=s.size();
    for(int i=slen;i<32;i++)
    {
        s='0'+s;
    }
    return s;
}

string subTotal(string s1, string s2)
{
    string result;
    for(int i=0;i<32;i++)
    {
        int n1=s1[i]-'0';
        int n2=s2[i]-'0';
        if(n1==n2) result+='0';
        else result+='1';
    }
    return result;
}

long long pow(int k)
{
    long long result=1;
    for(int i=0;i<k;i++)
    {
        result*=2;
    }
    return result;
}

void xorV(long long plusV, TRIE *N1, TRIE *N2, long long *result, long long sumV)
{
    if(!plusV)
    {
        if(*result < sumV) *result = sumV;
        return;
    }
    bool isF=false;
    if(N1->BIT[0] && N2->BIT[1])
    {
        isF=true;
        xorV(plusV/2, N1->BIT[0], N2->BIT[1], result, sumV+plusV);
    }
    if(N1->BIT[1] && N2->BIT[0])
    {
        isF=true;
        xorV(plusV/2, N1->BIT[1], N2->BIT[0], result, sumV+plusV);
    }
    if(isF) return;
    if(N1->BIT[0] && N2->BIT[0])
    {
        xorV(plusV/2, N1->BIT[0], N2->BIT[0], result, sumV);
    }
    if(N1->BIT[1] && N2->BIT[1])
    {
        xorV(plusV/2, N1->BIT[1], N2->BIT[1], result, sumV);
    }
}

void xorSum()
{
    int n;
    cin>>n;
    string startS;
    TRIE *Root=new TRIE();
    long long result=0;
    long long subTotV=0;
    for(int i=0;i<32;i++)
    {
        startS+='0';
    }
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        subTotV=subTotV^num;
        if(subTotV>result) result=subTotV;
        string numBit=bitMaker(num);
        startS=subTotal(startS,numBit);
        Root->insert(startS,0);
    }
    long long plusV=pow(31);
    TRIE *N=Root;
    while(true)
    {
        if(N->BIT[1] && N->BIT[0]) break;
        else if(N->BIT[0]) N=N->BIT[0];
        else if(N->BIT[1]) N=N->BIT[1];
        plusV/=2;
    }
    
    xorV(plusV/2,N->BIT[1], N->BIT[0],&result,plusV);
    cout<<result<<"\n";
    delete Root;
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        xorSum();
    }
}