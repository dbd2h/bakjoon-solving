#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
typedef long long ll;
typedef long double lld;
#define LEN 100001

using namespace std;

int main()
{
    string s;
    cin>>s;
    int arr[LEN];
    int len=s.size();
    for(int i=0;i<len;i++) arr[i]=0;
    int l=0;
    int mid=0;
    bool isR=true;
    for(int r=0;r<=len;r++)
    {
        char cur;
        if(r<len) cur=s[r];
        if(isR)
        {
            if(cur=='R') continue;
            mid=r;
            isR=false;
        }
        else
        {
            if(r<len && cur=='L') continue;
            int left=mid-l;
            int right=r-mid;
            if(left>right)
            {
                if(left%2==1)
                {
                    arr[mid-1]=(left+right)/2+(left+right)%2;
                    arr[mid]=(left+right)/2;
                }
                else
                {
                    arr[mid]=(left+right)/2+(left+right)%2;
                    arr[mid-1]=(left+right)/2;
                }
            }
            else
            {
                if(right%2==1)
                {
                    arr[mid]=(left+right)/2+(left+right)%2;
                    arr[mid-1]=(left+right)/2;
                }
                else
                {
                    arr[mid-1]=(left+right)/2+(left+right)%2;
                    arr[mid]=(left+right)/2;
                }
            }
            l=r;
            isR=true;
        }
    }
    for(int i=0;i<len;i++) cout<<arr[i]<<" ";
}