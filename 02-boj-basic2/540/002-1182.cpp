#include <iostream>

using namespace std;

void sum(int *arr, int n, int s, int index, int *result, int tot);

int main()
{
    int n, s;
    int result=0;
    cin>>n>>s;
    int numArr[n];
    for(int i=0;i<n;i++)
    {
        cin>>numArr[i];
    }
    sum(numArr, n, s, 0, &result, 0);
    cout<<result;
}

void sum(int *arr, int n, int s, int index, int *result, int tot)
{
    if(tot==s&&index!=0)
    {
        (*result)++;
    }
    for(int i=index;i<n;i++)
    {
        sum(arr, n, s, i+1, result, tot+arr[i]);
    }
}