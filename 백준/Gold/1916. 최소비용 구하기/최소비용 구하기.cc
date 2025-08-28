#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

int n, m;
vector<pair<int, int>> v[1001];
vector<int> dist;

void dijkstra(int start) {
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		auto now = pq.top();
		pq.pop();
		int cur = now.second;
		int cost = now.first;
		if (dist[cur] < cost) continue;
		for (auto p : v[cur]) {
			int next = p.second;
			int nextCost = p.first;
			if (dist[next] > dist[cur] + nextCost) {
				dist[next] = dist[cur] + nextCost;
				pq.push({ dist[next], next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	dist.assign(n + 1, 987654321);
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ cost, to });
	}
	int start, end;
	cin >> start >> end;
	dijkstra(start);
	cout << dist[end];
}