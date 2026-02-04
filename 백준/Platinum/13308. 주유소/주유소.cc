#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <climits>
using namespace std;

int n, m;
int oil[2501];
vector<pair<int, int>> graph[2501];
long long dist[2501][2501];
const long long INF = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> oil[i];
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 2500; j++) {
			dist[i][j] = INF;
		}
	}

	priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;
	dist[1][oil[1]] = 0;
	pq.push({ 0, 1, oil[1] });

	while (!pq.empty()) {
		long long cost = get<0>(pq.top());
		int cur = get<1>(pq.top());
		int mn = get<2>(pq.top());
		pq.pop();
		if (dist[cur][mn] < cost) continue;

		for (auto p : graph[cur]) {
			int next = p.first;
			long long ncost = cost + mn * p.second;
			int nmn = min(mn, oil[next]);
			if (dist[next][nmn] > ncost) {
				dist[next][nmn] = ncost;
				pq.push({ ncost, next, nmn });
			}
		}
	}

	long long ret = INF;
	for (int i = 1; i <= 2500; i++) {
		ret = min(ret, dist[n][i]);
	}
	cout << ret;
}