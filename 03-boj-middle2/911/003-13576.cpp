#include <iostream>
#include <string>
#include <stack>


using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    int kmp[100000]={0};
    int matched=0;
    int begin=1;
    int slen=s.size();
    int bit[100001]={0};
    while(begin<slen)
    {
        if(s[matched]==s[begin])
        {
            kmp[begin]=++matched;
            bit[matched]++;
            begin++;
        }
        else if(matched!=0)
        {
            matched=kmp[matched-1];
        }
        else
        {
            kmp[begin]=0;
            begin++;
        }
    }
    for(int i=slen-1;i>=1;i--)
    {
        if(!bit[i]) continue;
        if(!kmp[i-1]) continue;
        bit[kmp[i-1]]+=bit[i];
    }
    stack<int> st;
    int l=kmp[slen-1];
    while(l)
    {
        st.push(l);
        l=kmp[l-1];
    }
    cout<<st.size()+1<<"\n";
    while(!st.empty())
    {
        int t=st.top();
        st.pop();
        cout<<t<<" "<<bit[t]+1<<"\n";
    }
    cout<<slen<<" "<<1<<"\n";
}