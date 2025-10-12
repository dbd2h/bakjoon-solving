#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int binaryArr[31]={0};

int binarySearch(int l, int r, int num)
{
    int middle=(l+r)/2;
    if(binaryArr[middle]<num) return binarySearch(middle+1, r, num);
    else if(binaryArr[middle-1]<num) return middle;
    return binarySearch(l,middle-1,num);
}

void program()
{   
    int l,r;
    cin>>l>>r;
    if(r==0)
    {
        cout<<0<<"\n";
        cout<<0<<"\n";
        return;
    }
    int idx=binarySearch(0,30,r);
    int lastN=binaryArr[idx]^r;
    stack<int> st;
    int copyN=lastN;
    int c=r;
    while(copyN<=r)
    {
        st.push(copyN);
        copyN++;
        c--;
    }
    if(c>=1)
    {
        idx=binarySearch(0,30,c);
        lastN=binaryArr[idx]^c;
        r=c;
    }
    
    while(c>=1)
    {
        copyN=lastN;
        while(copyN<=r)
        {
            st.push(copyN);
            copyN++;
            c--;
        }
        if(c>=1)
        {
            idx=binarySearch(0,30,c);
            lastN=binaryArr[idx]^c;
            r=c;
        }
    }
    if(c==0) st.push(0);
    int count=0;
    long long sum=0;
    vector<int> v;
    while(!st.empty())
    {
        int cur=st.top();
        st.pop();
        v.push_back(cur);
        sum+=((long long)cur^(long long)count);
        count++;
    }
    cout<<sum<<"\n";
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}   

int main()
{
    int num=1;
    for(int i=0;i<31;i++)
    {
        num*=2;
        binaryArr[i]=num-1;
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}