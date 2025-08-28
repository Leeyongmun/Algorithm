#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;

int v, e, start;
vector<pair<int, int>> adj[20001];
vector<int> dist;

void dijkstra(int start) {
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, start });
	while (pq.size()) {
		int cur_dist = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		if (cur_dist > dist[u]) continue;

		for (auto p : adj[u]) {
			if (dist[p.first] > dist[u] + p.second) {
				dist[p.first] = dist[u] + p.second;
				pq.push({ dist[p.first], p.first });
			}
		}
	}
}

int main() {
	cin >> v >> e >> start;
	dist.assign(v + 1, 987654321);
	for (int i = 0; i < e; i++) {
		int from, to, w;
		cin >> from >> to >> w;
		adj[from].push_back({ to, w });
	}
	dijkstra(start);

	for (int i = 1; i <= v; i++) {
		if (dist[i] == 987654321) {
			cout << "INF" << '\n';
		}
		else {
			cout << dist[i] << '\n';
		}
	}
}
