#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int n, m;
vector<pair<int, int>> graph[50001];
vector<int> dist;

void dijkstra(int start) {
	dist.assign(n + 1, 987654321);
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int w = -pq.top().first;
		int cur = pq.top().second;
		if (cur == n) break;
		pq.pop();
		if (dist[cur] < w) continue;
		for (auto p : graph[cur]) {
			int next = p.second;
			int nw = w + p.first;
			if (dist[next] > nw) {
				dist[next] = nw;
				pq.push({ -nw, next });
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ c, b });
		graph[b].push_back({ c, a });
	}
	dijkstra(1);
	cout << dist[n];
}