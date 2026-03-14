#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int arr[10]={4,3,1,2,0};
    sort(arr,arr+2);
    cout<<arr[1];
}