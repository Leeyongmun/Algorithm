#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<string>
#include<cmath>
#include<set>
#include<queue>

using namespace std;

int n, m;
vector<int> graph[50001];
int parent[50001][16];
int depth[50001];

void dfs(int cur) {
	for (int next : graph[cur]) {
		if (depth[next] == -1) {
			parent[next][0] = cur;
			depth[next] = depth[cur] + 1;
			dfs(next);
		}
	}
}

void connection() {
	for (int i = 1; i < 16; i++) {
		for (int cur = 1; cur <= n; cur++) {
			parent[cur][i] = parent[parent[cur][i - 1]][i - 1];
		}
	}
}

int LCA(int a, int b) {
	if (depth[a] < depth[b]) {
		swap(a, b);
	}
	int diff = depth[a] - depth[b];

	for (int i = 0; diff != 0; i++) {
		if (diff % 2 == 1) {
			a = parent[a][i];
		}
		diff /= 2;
	}

	if (a != b) {
		for (int i = 15; i >= 0; i--) {
			if (parent[a][i] != -1 && parent[a][i] != parent[b][i]) {
				a = parent[a][i];
				b = parent[b][i];
			}
		}
		a = parent[a][0];
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	fill(depth, depth + 50001, -1);
	depth[1] = 0;
	dfs(1);
	connection();
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}
	return 0;
}