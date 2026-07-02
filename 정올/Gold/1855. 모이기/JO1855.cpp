#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include <set>
#include <map>
using namespace std;

int n, p, c;
vector<pair<int, int>> graph[801];
vector<int> dist[801];
unordered_map<int, int> mp;
const int INF = 1e9;

void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	dist[start][start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (dist[start][cur] < cost) continue;

		for (auto p : graph[cur]) {
			int next = p.first;
			int ncost = cost + p.second;
			if (dist[start][next] > ncost) {
				dist[start][next] = ncost;
				pq.push({ ncost, next });
			}
		}
	}
}

int main() {
	cin >> n >> p >> c;
	for (int i = 0; i < c; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to, cost });
		graph[to].push_back({ from, cost });
	}

	for (int i = 1; i <= p; i++) {
		dist[i].assign(p + 1, INF);
	}

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mp[x]++;
	}

	int ret = 987654321;

	for (auto pa : mp) {
		int start = pa.first;
		dijkstra(start);
	}

	for (int i = 1; i <= p; i++) {
		int sum = 0;
		for (auto pa : mp) {
			if (dist[pa.first][i] == INF) {
				sum = INF;
				break;
			}
			sum += dist[pa.first][i] * pa.second;
		}
		ret = min(ret, sum);
	}
	cout << ret;
}
