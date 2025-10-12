#include <iostream>
#include <queue>
#include <vector>
#include <string>

struct Node {
	int idx;
	int pCost;
	int w1;
	int w2;
};

struct cmp {
	bool operator()(const Node a, const Node b)
	{
		if (a.pCost > b.pCost)
			return true;
		else if (a.pCost == b.pCost)
		{
			if (a.idx > b.idx)
				return true;
			else
				return false;
		}
		return false;
	}
};

std::vector<std::pair<int, int> > varr[2][21];
int dist[2][21];
int INF = 1e8;

int Dijkstra(int S, int D)
{
	std::priority_queue<Node, std::vector<Node>, cmp> pq;
	pq.push({S, 0, 0, 0});
	dist[0][S] = 0;
	dist[1][S] = 0;
	while (!pq.empty())
	{
		int here = pq.top().idx;
		int cost = pq.top().pCost;
		int w1 = pq.top().w1;
		int w2 = pq.top().w2;
		pq.pop();
		if (here == D)
			return cost;
		if (w1 > dist[0][here] && w2 > dist[1][here])
			continue;
		for (int i = 0; i < varr[0][here].size(); i++)
		{
			int there = varr[0][here][i].first;
			int nw1 = w1 + varr[0][here][i].second;
			int nw2 = w2 + varr[1][here][i].second;
			int nextDis = nw1 * nw2;
			if (dist[0][there] > nw1 || dist[1][there] > nw2)
			{
				dist[0][there] = std::min(dist[0][there], nw1);
				dist[1][there] = std::min(dist[1][there], nw2);
				pq.push({there, nextDis, nw1, nw2});
			}
		}
	}
	return -1;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int N;

	std::cin >> N;
	std::string str;
	for (int i = 0; i < 2 * N; i++)
	{
		std::cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] != '.')
			{
				if (i >= N)
				{
					varr[1][i % N].push_back(std::make_pair(j, str[j] - '0'));
					varr[1][j].push_back(std::make_pair(i % N, str[j] - '0'));
				}
				else
				{
					varr[0][i % N].push_back(std::make_pair(j, str[j] - '0'));
					varr[0][j].push_back(std::make_pair(i % N, str[j] - '0'));
				}
			}
		}
	}
	for (int i = 0; i < 21; i++)
	{
		dist[0][i] = INF;
		dist[1][i] = INF;
	}
	std::cout << Dijkstra(0, 1) << std::endl;
	return 0;
}