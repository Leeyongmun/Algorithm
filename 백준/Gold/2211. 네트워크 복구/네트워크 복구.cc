#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <climits>
using namespace std;

int n, m;
vector<pair<int, int>> graph[1001];
int dist[1001];
int parent[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	fill(dist, dist + 1001, 987654321);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 1 });
	dist[1] = 0;
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
				parent[next] = cur;
				pq.push({ nc, next });
			}
		}
	}
	cout << n - 1 << '\n';
	for (int i = 2; i <= n; i++) {
		cout << i << " " << parent[i] << '\n';
	}
}