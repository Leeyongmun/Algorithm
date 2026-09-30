#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include<set>
#include<map>
#include<stack>
#include<cctype>
#include<string>
#include<sstream>
using namespace std;
using ll = long long;

int n, m;
vector<pair<int, int>> graph[100001];
int dist[100001];
const int INF = 2000000001;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	fill(dist, dist + 100001, INF);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, 1 });
	dist[1] = 0;

	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (cur == n) {
			cout << dist[cur];
			break;
		}

		if (dist[cur] < cost) continue;

		for (auto p : graph[cur]) {
			int next = p.first;
			int ncost = cost + p.second;
			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push({ ncost, next });
			}
		}
	}
}
