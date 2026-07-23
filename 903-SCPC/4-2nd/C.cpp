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
    #define INF (ll)(1e18)

    using namespace std;
    priority_queue<pair<ll,pair<int,int>>,vector<pair<ll,pair<int,int>>>,greater<pair<ll,pair<int,int>>>> pqLo; // w, node
    priority_queue<pair<ll,pair<int,int>>> pqHi;
    vector<int> dGraph[LEN];
    ll node[LEN]; // w

    int cmp(pair<int,int> p1, pair<int,int> p2)
    {
        return node[p1.first]<node[p2.first];
    }

    void program()
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            node[i]=INF;
        } 
        for(int i=0;i<m;i++)
        {
            int a,b;
            ll c;
            cin>>a>>b>>c;
            pqLo.push({c,{a,b}});
            pqLo.push({c,{b,a}});
            pqHi.push({c,{a,b}});
            pqHi.push({c,{b,a}});
        }
        node[1]=0;
        ll w;
        while(!pqLo.empty())
        {
            w=pqLo.top().first;
            vector<int> v;
            priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
            while(!pqLo.empty() && pqLo.top().first==w)
            {
                int a,b;
                a=pqLo.top().second.first;
                b=pqLo.top().second.second;
                if(node[a]!=INF) pq.push({node[a],a});
                v.push_back(a);
                dGraph[a].push_back(b);
                pqLo.pop();
            }
            while(!pq.empty())
            {
                ll curW=pq.top().first;
                int cur=pq.top().second;
                pq.pop();
                if(curW>node[cur]) continue;
                for(auto&next : dGraph[cur])
                {
                    if(node[next]>curW+w)
                    {
                        node[next]=curW+w;
                        pq.push({node[next],next});
                    }
                }
            }
            for(auto&next: v) dGraph[next].clear();
        }
        while(!pqHi.empty())
        {
            w=pqHi.top().first;
            vector<int> v;
            priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
            while(!pqHi.empty() && pqHi.top().first==w)
            {
                int a,b;
                a=pqHi.top().second.first;
                b=pqHi.top().second.second;
                if(node[a]!=INF) pq.push({node[a],a});
                v.push_back(a);
                dGraph[a].push_back(b);
                pqHi.pop();
            }
            while(!pq.empty())
            {
                ll curW=pq.top().first;
                int cur=pq.top().second;
                pq.pop();
                if(curW>node[cur]) continue;
                for(auto&next : dGraph[cur])
                {
                    if(node[next]>curW+w)
                    {
                        node[next]=curW+w;
                        pq.push({node[next],next});
                    }
                }
            }
            for(auto&next: v) dGraph[next].clear();
        }
        if(node[n]==INF) cout<<-1<<endl;
        else cout<<node[n]<<endl;
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