#include <iostream>
#include <string>
#include <deque>
#include <vector>

using namespace std;

int maxV(int n1, int n2)
{
    if(n1>n2) return n1;
    else return n2;
}
int minV(int n1, int n2)
{
    if(n1>n2) return n2;
    else return n1;
}

int main()
{
    int MAXLEN=300001;
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a,t;
    cin>>a>>t;
    int tsize=t.size();
    int asize=a.size();
    int fi=0;
    int li=tsize-1;
    deque<char> fdq,ldq;
    while(fi<=li)
    {
        while(fi<=li)
        {
            fdq.push_back(t[fi++]);
            if(fdq.size()<asize) continue;
            int index=fdq.size()-asize;
            int isDiff=0;
            for(int i=0;i<asize;i++)
            {
                if(fdq[index+i]!=a[i])
                {
                    isDiff=1;
                    break;
                }
            }
            if(isDiff) continue;
            for(int i=0;i<asize;i++)
            {
                fdq.pop_back();
            }
            break;
        }
        while(fi<=li)
        {
            ldq.push_front(t[li--]);
            if(ldq.size()<asize) continue;
            int index=ldq.size()-asize;
            int isDiff=0;
            for(int i=0;i<asize;i++)
            {
                if(ldq[i]!=a[i])
                {
                    isDiff=1;
                    break;
                }
            }
            if(isDiff) continue;
            for(int i=0;i<asize;i++)
            {
                ldq.pop_front();
            }
            break;
        }
    }
    string result;
    int fdqSize=fdq.size();
    int ldqSize=ldq.size();
    for(int i=0;i<fdqSize;i++)
    {
        result.push_back(fdq.front());
        fdq.pop_front();
    }
    for(int i=0;i<ldqSize;i++)
    {
        result.push_back(ldq.front());
        ldq.pop_front();
    }
    while(result.find(a)<MAXLEN)
    {
        result.erase(result.find(a), asize);
    }
    if(!result.empty()) cout<<result;
     
}