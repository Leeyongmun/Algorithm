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
int s, e;
vector<pair<int, int>> graph[100001];
map<pair<int, int>, int> mp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	cin >> s >> e;

	for (int i = 0; i < m; i++) {
		int from, to, k;
		cin >> from >> to >> k;
		if (from > to) swap(from, to);
		if (mp[{from, to}] < k) {
			mp[{from, to}] = k;
		}
	}
	for (auto p : mp) {
		int from = p.first.first;
		int to = p.first.second;
		int k = p.second;
		graph[from].push_back({ to, k });
		graph[to].push_back({ from, k });
	}
	
	vector<int> dist(100001, 0);
	priority_queue<pair<int, int>> pq;
	pq.push({ 987654321, s });
	dist[s] = 987654321;

	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (cost < dist[cur]) continue;
		if (cur == e) break;
		for (auto p : graph[cur]) {
			int next = p.first;
			int nc = min(cost, p.second);
			if (dist[next] < nc) {
				dist[next] = nc;
				pq.push({ nc, next });
			}
		}
	}

	cout << dist[e];
}