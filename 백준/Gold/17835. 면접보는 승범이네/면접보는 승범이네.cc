#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<deque>
#include<queue>
#include<string>

using namespace std;

int n, m, k;
vector<pair<int, int>> graph[100001];
vector<long long> dist(100001, 10000000003);
long long mx = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[b].push_back({ a, c });
	}
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	for (int i = 0; i < k; i++) {
		int p;
		cin >> p;
		pq.push({ 0, p });
		dist[p] = 0;
	}
	while (!pq.empty()) {
		long long cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < cost) continue;
		for (auto p : graph[cur]) {
			int next = p.first;
			long long nc = cost + p.second;
			if (dist[next] > nc) {
				dist[next] = nc;
				pq.push({ nc, next });
			}
		}
	}
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] != 987654321 && dist[i] > mx) {
			mx = dist[i];
			idx = i;
		}
	}
	cout << idx << '\n' << mx;
}