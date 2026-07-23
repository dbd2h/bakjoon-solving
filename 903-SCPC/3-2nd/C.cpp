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
    #define LEN 1000001
    #define aLEN 100001


    using namespace std;
    int arr1[aLEN];
    int arr2[aLEN][2];
    vector<int> v[aLEN];
    int bit[LEN]={0};
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    void program()
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<LEN;i++) bit[i]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>arr1[i];
            v[i].clear();
        } 
        for(int i=1;i<=m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            pq.push({b-1,i});
            pq.push({c,i});
            arr2[i][0]=a;
            arr2[i][1]=0;
        }
        int I=0;
        ll res=0;
        while(!pq.empty())
        {
            int l=pq.top().first;
            int idx=pq.top().second;
            int num=arr2[idx][0];
            pq.pop();
            while(I<l)
            {
                I++;
                int cur=arr1[I];
                for(int i=1;i<=1000;i++)
                {
                    if(i*i>cur) break;
                    if(cur%i!=0) continue;
                    int div=cur/i;
                    bit[i]++;
                    if(div!=i) bit[div]++;
                }
            }
            if(arr2[idx][1]==0)
            {
                for(int i=1;i<=1000;i++)
                {
                    if(i*i>num) break;
                    if(num%i!=0) continue;
                    int div=num/i;
                    v[idx].push_back(bit[i]);
                    if(div!=i) v[idx].push_back(bit[div]);
                }
                arr2[idx][1]=1;
            }
            else
            {
                int curI=0;
                for(int i=1;i<=1000;i++)
                {
                    if(i*i>num) break;
                    if(num%i!=0) continue;
                    int div=num/i;
                    if(v[idx][curI]==bit[i]) res++;
                    curI++;
                    if(div!=i && v[idx][curI]==bit[div]) res++;
                    curI++;
                }
            }
        }
        cout<<res<<endl;    
    }

    int main()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int t;
        cin>>t;
        for(int i=1;i<=t;i++)
        {
            cout<<"Case #"<<i<<endl;
            program();
        }
    }