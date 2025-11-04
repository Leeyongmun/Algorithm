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

int n, m, h;
vector<int> tree[100001];
vector<vector<int>> parent;
vector<int> depth(100001, -1);

void dfs(int cur) {
	for (int next : tree[cur]) {
		if (depth[next] != -1) continue;
		depth[next] = depth[cur] + 1;
		parent[0][next] = cur;
		dfs(next);
	}
}

void connection() {
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}
}

int LCA(int a, int b) {
	if (depth[a] < depth[b]) {
		swap(a, b);
	}

	int diff = depth[a] - depth[b];

	for (int i = 0; i <= h; i++) {
		if (diff & (1 << i)) a = parent[i][a];
	}

	if (a != b) {
		for (int i = h; i >= 0; i--) {
			if (parent[i][a] != -1 && parent[i][a] != parent[i][b]) {
				a = parent[i][a];
				b = parent[i][b];
			}
		}
		a = parent[0][a];
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int len = 1;
	while (len < n) {
		len <<= 1;
		h++;
	}
	parent.assign(h + 1, vector<int>(100001));
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	depth[1] = 0;
	dfs(1);
	connection();
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}
}