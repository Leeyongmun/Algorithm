#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

int n, m, k;
long long ret = -1;
int idx = -1;
vector<pair<int, int>> v[100001];
vector<long long> dist;
vector<int> interview;

void dijkstra() {
	dist.assign(n + 1, 30000000000);
	priority_queue<pair<long long, int>> pq;
	for (int i = 0; i < k; i++) {
		dist[interview[i]] = 0;
		pq.push({ 0, interview[i] });
	}
	while (!pq.empty()) {
		int cur = pq.top().second;
		long long cost = -pq.top().first;
		pq.pop();
		if (dist[cur] < cost) continue;
		for (auto p : v[cur]) {
			int next = p.first;
			int nCost = p.second;
			long long nd = cost + nCost;
			if (dist[next] > nd) {
				dist[next] = nd;
				pq.push({ -nd, next });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dist[i] != 30000000000 && dist[i] > ret) {
			ret = dist[i];
			idx = i;
		}
	}
}

int main() {
	cin >> n >> m >> k;
	dist.resize(n + 1);
	interview.resize(k);
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[to].push_back({ from, cost });
	}
	for (int i = 0; i < k; i++) {
		cin >> interview[i];
	}
	dijkstra();
	cout << idx << '\n' << ret;
}