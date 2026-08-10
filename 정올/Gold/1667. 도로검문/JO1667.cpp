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
using ll = long long;

int n, m;
vector<pair<int, int>> graph[1001];
vector<pair<int, int>> path;
int dist[1001];
int parent[1001];

struct State {
	int cost, cur, prev;

	bool operator > (const State& other) const {
		return cost > other.cost;
	}
};

int dijkstra(int a, int b, bool flag = false) {
	fill(dist, dist + 1001, 1e9);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, 1 });
	dist[1] = 0;

	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (dist[cur] < cost) continue;

		for (auto p : graph[cur]) {
			int next = p.first;
			int ncost = cost + p.second;
			if ((cur == a && next == b) || cur == b && next == a) continue;
			if (dist[next] > ncost) {
				dist[next] = ncost;
				if (flag) {
					parent[next] = cur;
				}
				pq.push({ ncost, next });
			}
		}
	}
	return dist[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		graph[a].push_back({ b, t });
		graph[b].push_back({ a, t });
	}

	int time = dijkstra(-1, -1, true);
	int cur = n;

	while (cur != 1) {
		int prev = parent[cur];
		path.push_back({ prev, cur });
		cur = prev;
	}
	
	int ret = 0;

	for (auto p : path) {
		int ntime = dijkstra(p.first, p.second);
		if (dist[n] == 1e9) {
			cout << -1;
			return 0;
		}
		ret = max(ret, ntime - time);
	}

	cout << ret;
}
