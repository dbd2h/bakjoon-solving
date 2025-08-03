#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    cin>>a>>b;
    int kmp[100000]={0};
    int asize=a.size();
    int bsize=b.size();
    int i=0;
    int j=1;
    while(j<asize)
    {
        if(a[i]==a[j])
        {
            kmp[j]=++i;
            j++;
        }
        else if(i!=0)
        {
            i=kmp[i-1];
        }
        else
        {
            kmp[j]=0;
            j++;
        }
    }
    int result=0;
    int aI=0;
    int bI=0;
    while(bI<2*bsize-1)
    {

        if(a[aI]==b[bI%bsize])
        {
            aI++;
            if(aI==asize)
            {
                result++;
                aI=kmp[aI-1];
            }
            bI++;
        }
        else if(aI!=0)
        {
            aI=kmp[aI-1];
        }
        else
        {
            bI++;
        }
    }
    cout<<result;
}