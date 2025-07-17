#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int arr[1000001]={0};
    int s=0;
    for(int i=1;i<=n;i++)
    {
        int num;
        cin>>num;
        if(arr[s]>=num)
        {
            int* index=lower_bound(arr, arr+s, num);
            *index=num;
            continue;
        }
        s++;
        arr[s]=num;
    }
    cout<<s<<"\n";
}