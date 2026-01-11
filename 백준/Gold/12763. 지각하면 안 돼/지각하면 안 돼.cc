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

int n;
int t, m;
int l;
vector<tuple<int, int, int>> graph[10001];
int dist[101][10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> t >> m;
	cin >> l;
	for (int i = 0; i < l; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		graph[a].push_back({ b, c, d });
		graph[b].push_back({ a, c, d });
	}
	fill(&dist[0][0], &dist[0][0] + 101 * 10001, 987654321);
	dist[1][0] = 0;
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({ 0, {1, 0} });
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		int c = p.first;
		int cur = p.second.first;
		int ct = p.second.second;
		if (c > dist[cur][ct]) continue;
		for (auto np : graph[cur]) {
			int next = get<0>(np);
			int time = get<1>(np);
			int cost = get<2>(np);
			int nt = ct + time;
			if (nt > t) continue;
			int nc = c + cost;
			if (dist[next][nt] > nc) {
				dist[next][nt] = nc;
				pq.push({ nc, {next, nt} });
			}
		}
	}
	int ret = 987654321;
	for (int i = 0; i <= t; i++) {
		ret = min(ret, dist[n][i]);
	}
	if (ret <= m) cout << ret;
	else cout << -1;
}