#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

int n, m, d, e;
int h[100001];
vector<pair<int,int>> graph[100001];
long long ret = -5000000000000000LL;

vector<long long> dijkstra(int start) {
	vector<long long> dist(n + 1, 5000000000000000LL);
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cur = pq.top().second;
		long long c = pq.top().first;
		pq.pop();
		if (dist[cur] < c) continue;
		for (auto p : graph[cur]) {
			int next = p.first;
			long long nc = c + p.second;
			if (dist[next] > nc && h[next] > h[cur]) {
				dist[next] = nc;
				pq.push({ nc, next });
			}
		}
	}
	return dist;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> d >> e;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}

	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to, cost });
		graph[to].push_back({ from, cost });
	}

	vector<long long> dist1 = dijkstra(1);
	vector<long long> dist2 = dijkstra(n);

	for (int i = 2; i < n; i++) {
		if (dist1[i] + dist2[i] < 5000000000000000LL) {
			ret = max(ret, h[i] * e - (dist1[i] + dist2[i]) * d);
		}
	}
	if (ret == -5000000000000000LL) cout << "Impossible";
	else cout << ret;
}