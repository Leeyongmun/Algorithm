#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>

using namespace std;

int n, m;
vector<pair<int, int>> graph[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to, cost });
	}
	int s, e;
	cin >> s >> e;
	vector<int> dist(n + 1, 987654321);
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, s });
	dist[s] = 0;
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (dist[cur] < cost) continue;
		for (auto p : graph[cur]) {
			int next = p.first;
			int nc = cost + p.second;
			if (dist[next] > nc) {
				dist[next] = nc;
				pq.push({ nc, next });
			}
		}
	}
	cout << dist[e];
}