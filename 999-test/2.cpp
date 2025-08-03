#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int len[5000];
int cnt[300001];
vector<pair<int,int>> v;
struct Trie 
{
	vector<pair<char, Trie*>> NODE;
	int prefix;
	Trie* fail;
	Trie() 
	{
		prefix = -1;
		NODE.clear();
		fail = NULL;
	}
	void insert(const char* s, int num) 
	{
		if (!*s) 
		{
			prefix = num;
			return;
		}
		int now = *s - 'a';
		for (auto& i : NODE) 
		{
			if (i.first == now) return i.second->insert(s + 1, num);
		}
		NODE.push_back({ now, new Trie() });
		NODE.back().second->insert(s + 1, num);
	}
	void aho() 
	{
		queue<Trie*> q;
		q.push(this);
		while (!q.empty()) 
		{
			Trie* now = q.front(); 
			q.pop();
			for (auto& i : now->NODE) 
			{
				Trie* next = i.second;
				if (now == this) next->fail = this;
				else 
				{
					Trie* dest = now->fail;
					while (dest != this) {
						bool flag = true;
						for (auto j : dest->NODE) 
						{
							if (j.first == i.first) 
							{
								flag = false;
								break;
							}
						}
						if (!flag) break;
						dest = dest->fail;
					}
					for (auto j : dest->NODE) 
					{
						if (j.first == i.first) 
						{
							dest = j.second;
							break;
						}
					}
					next->fail = dest;
				}
				if (next->fail->prefix>=0) 
				{
					if (next->prefix == -1 || (len[next->fail->prefix] > len[next->prefix])) next->prefix = next->fail->prefix;
				}
				q.push(next);
			}
		}
	}
	void query(string s)
	{
		Trie* cur = this;
		for (int i = 0; i < s.size(); i++) 
		{
			int now = s[i] - 'a';
			while (cur != this) 
			{
				bool flag = true;
				for (auto j : cur->NODE)
				{
					if (j.first == now)
					{
						flag = false; 
						break;
					}
				}
				if (!flag) break;
				cur = cur->fail;
			}
			for (auto j : cur->NODE) 
			{
				if (j.first == now) 
				{
					cur = j.second;
					break;
				}
			}
			if (cur->prefix >= 0) v.push_back({ i - len[cur->prefix] + 1, i });
		}
	}
};
int main(void) 
{
	cin.tie(0); 
	cout.tie(0);
	ios::sync_with_stdio(false); 
	Trie* Root = new Trie();
	int n; 
	cin >> n;
	string s; 
	cin >> s;
	int m; 
	cin >> m;
	vector<string> tile(m);
	for (int i = 0; i < m; i++) 
	{
		cin >> tile[i];
		len[i] = tile[i].size();
		Root->insert(tile[i].c_str(), i);
	}
	Root->aho();
	Root->query(s);
	sort(v.begin(),v.end());
	int last = -1;
	int ans = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (last < v[i].first) ans += v[i].first - last-1;
		last = max(last, v[i].second);
	}
	ans += s.size() - 1 - last;
	cout << ans;
}