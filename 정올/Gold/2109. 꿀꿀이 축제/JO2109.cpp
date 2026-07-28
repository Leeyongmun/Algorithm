#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include <set>
#include <map>
#include <stack>
using namespace std;

int n, m, x;
vector<pair<int,int>> graph[1001];
vector<pair<int, int>> revgraph[1001];

int dist1[1001], dist2[1001];

void dijkstra(vector<pair<int, int>> g[], int dist[]) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	dist[x] = 0;
	pq.push({ 0, x });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (dist[cur] < cost) continue;

		for (auto p : g[cur]) {
			int next = p.first;
			int ncost = cost + p.second;

			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push({ ncost, next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> x;

	fill(dist1, dist1 + 1001, 987654321);
	fill(dist2, dist2 + 1001, 987654321);

	for (int i = 0; i < m; i++) {
		int from, to, t;
		cin >> from >> to >> t;
		graph[from].push_back({ to, t });
		revgraph[to].push_back({ from, t });
	}

	dijkstra(graph, dist1);
	dijkstra(revgraph, dist2);

	int ret = 0;

	for (int i = 1; i <= n; i++) {
		ret = max(ret, dist1[i] + dist2[i]);
	}

	cout << ret;
}
