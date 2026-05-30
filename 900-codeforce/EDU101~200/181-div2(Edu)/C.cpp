#include <iostream>

using namespace std;

void countGoodNumbers()
{
    long long l,r;
    cin>>l>>r;
    long long result=(r-l+1);
    result-=((r/2-(l-1)/2)+(r/3-(l-1)/3)+(r/5-(l-1)/5)+(r/7-(l-1)/7));
    result+=((r/6-(l-1)/6)+(r/10-(l-1)/10)+(r/14-(l-1)/14)+(r/15-(l-1)/15)+(r/21-(l-1)/21)+(r/35-(l-1)/35));
    result-=((r/30-(l-1)/30)+(r/42-(l-1)/42)+(r/70-(l-1)/70)+(r/105-(l-1)/105));
    result+=(r/210-(l-1)/210);
    cout<<result<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        countGoodNumbers();
    }
}