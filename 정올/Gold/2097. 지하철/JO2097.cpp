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

int n, m;
int a[101][101];
int pre[101];
int dist[101];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	fill(dist, dist + 101, 987654321);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, 1 });
	dist[1] = 0;
	pre[1] = -1;
	
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (cur == m) break;
		if (dist[cur] < cost) continue;

		for (int i = 1; i <= n; i++) {
			if (i == cur) continue;
			int ncost = cost + a[cur][i];
			if (dist[i] > ncost) {
				dist[i] = ncost;
				pq.push({ ncost, i });
				pre[i] = cur;
			}
		}
	}

	cout << dist[m] << '\n';
	int cur = m;
	vector<int> path;
	while (cur != -1) {
		path.push_back(cur);
		cur = pre[cur];
	}

	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << ' ';
	}
}
