#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<string>
#include<unordered_set>
#include<stack>
#include<cmath>
#include<queue>
using namespace std;

int n;
vector<pair<int,int>> tree[50001];

vector<int> bfs(int now) {
	vector<int> visited(n + 1, 0);
	queue<int> q;
	visited[now] = 1;
	q.push(now);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto p : tree[cur]) {
			int next = p.first;
			int dist = p.second;
			if (visited[next]) continue;
			visited[next] = visited[cur] + dist;
			q.push(next);
		}
	}
	return visited;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int from, to, dist;
		cin >> from >> to >> dist;
		tree[from].push_back({ to, dist });
		tree[to].push_back({ from, dist });
	}
	vector<int> dist = bfs(1);
	int a = -1;
	int mx = -1;
	for (int i = 1; i <= n; i++) {
		if (mx < dist[i]) {
			a = i;
			mx = dist[i];
		}
	}
	vector<int> dist_a = bfs(a);
	int b = -1;
	mx = -1;
	for (int i = 1; i <= n; i++) {
		if (mx < dist_a[i]) {
			b = i;
			mx = dist_a[i];
		}
	}
	vector<int> dist_b = bfs(b);
	for (int i = 1; i <= n; i++) {
		cout << (dist_a[i] > dist_b[i] ? dist_a[i] - 1 : dist_b[i] - 1) << '\n';
	}
}