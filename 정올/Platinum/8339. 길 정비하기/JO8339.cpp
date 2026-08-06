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

int n, m, k;
vector<pair<int, int>> graph[10001];
ll dist[10001][21];

struct State {
	int cur, cnt;
	ll cost;

	bool operator > (const State& other) const {
		return cost > other.cost;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	fill(&dist[0][0], &dist[0][0] + 10001 * 21, (1LL << 60));
	priority_queue<State, vector<State>, greater<>> pq;
	pq.push({ 1, 0, 0 });
	dist[1][0] = 0;

	while (!pq.empty()) {
		State now = pq.top();
		pq.pop();

		int cur = now.cur;
		ll cost = now.cost;
		int cnt = now.cnt;

		if (cur == n) {
			cout << cost;
			break;
		}

		if (dist[cur][cnt] < cost) continue;

		for (auto p : graph[cur]) {
			int next = p.first;
			ll ncost = cost + p.second;
			if (dist[next][cnt] > ncost) {
				dist[next][cnt] = ncost;
				pq.push({ next, cnt, ncost });
			}
			if (cnt < k && dist[next][cnt + 1] > cost) {
				dist[next][cnt + 1] = cost;
				pq.push({ next, cnt + 1, cost });
			}
		}
	}
}
