#include <iostream>
#include <vector>

using namespace std;

int Answer;

void problem()
{
    Answer = 0;
	int n;
	cin>>n;
	int arr[3]={0};
	vector<int> v;
	for(int i=0;i<n;i++)
    {
	    int num;
	    cin>>num;
        v.push_back(num);
	}
	for(auto& num : v)
	{
	    if(num==500)
		{
		        arr[0]++;
		}
	    else if(num==1000)
	    {
		    if(arr[0]==0) break;
		    arr[0]--;
	        arr[1]++;
	    }
		else
	    {
	        if(arr[0]>=1 && arr[1]>=4)
		    {
		        arr[0]-=1;
		        arr[1]-=4;
	        }
		    else if(arr[0]>=3 && arr[1]>=3)
		    {
	            arr[0]-=3;
	            arr[1]-=3;
		    }
		    else if(arr[0]>=5 && arr[1]>=2)
	        {
	            arr[0]-=5;
		        arr[1]-=2;
		    }
		    else if(arr[0]>=7 && arr[1]>=1)
	        {
	            arr[0]-=7;
		        arr[1]-=1;
		    }
		    else if(arr[0]>=9)
	        {
	            arr[0]-=9;
		    }
	        else break;
	    }
		Answer++;
	}
    cout<<Answer<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<"\n";
        problem();
    }
}