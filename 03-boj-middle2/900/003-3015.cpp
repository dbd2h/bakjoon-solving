#include <iostream>
#include <queue>

using namespace std;

long long arr[500001]={0};

void segment(int l, int r, long long *s, int isR)
{
    if(l==r)
    {
        return;
    }
    int middle=(l+r)/2;
    segment(l,middle,s,0);
    segment(middle+1,r,s,1);
    int li=middle;
    int ri=middle+1;
    int lm=arr[li];
    int rm=arr[ri];
    int lc=1;
    int mm=0;
    queue<int> q;
    q.push(lm);
    while(true)
    {
        if(ri>r) break;
        
        if(li>=l && lm<=rm)
        {
            while(li>=l)
            {
                li--;
                if(li<l) break;
                if(arr[li]>=lm)
                {
                    q.push(arr[li]);
                    lm=arr[li];
                    lc++;
                }
                if(lm>rm) break;
            }
        }
        (*s)+=lc;
        if(li<l && lm<rm) break;

        while(ri<=r)
        {
            ri++;
            if(ri > r) break;
            if(rm<=arr[ri])
            {
                if(mm<rm) mm=rm;
                rm=arr[ri];
                break;
            }
        }
        while(!q.empty() && q.front()<mm)
        {
            q.pop();
            lc--;
        }
        //cout<<lc<<" "<<li<<" "<<ri<<" "<<lm<<" "<<rm<<"\n";
    }
    //cout<<"asdf"<<" "<<l<<" "<<r<<" "<<(*s)<<"\n";
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    long long result=0;
    segment(1,n,&result,0);
    cout<<result;
}

// 14
// 7 7 8 6 5 3 7 4 7 7 10 6 1 2

// 10
// 10 9 1 3 8 6 7 8 5 8

// 13
// 8 8 7 7 7 6 6 7 7 7 7 9 9