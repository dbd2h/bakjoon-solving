#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[200000][2]={0};
    int maxr=-1;
    int maxc=-1;
    int minr=-1;
    int minc=-1;
    for(int i=0;i<n;i++)
    {
        int r,c;
        cin>>r>>c;
        if(maxr==-1)
        {
            maxr=r;
            minr=r;
            maxc=c;
            minc=c;
            continue;
        }
        if(maxr<r) maxr=r;
        if(maxc<c) maxc=c;
        if(minr>r) minr=r;
        if(minc>c) minc=c;
    }
    int res=maxr-minr;
    if(res<maxc-minc) res=maxc-minc;
    cout<<(res+1)/2;
}