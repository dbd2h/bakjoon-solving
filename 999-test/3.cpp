#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a<b;
}

int main()
{
    int arr[10]={0};
    for(int i=1;i<=10;i++)
    {
        arr[i-1]=i;
    }
    sort(arr,arr+10,compare);
    cout<<arr[0];
}