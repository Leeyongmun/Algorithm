#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<cmath>

using namespace std;

int n;
vector<vector<int>> tree;
vector<long long> val, ind, dp;

void dfs(int cur, int parent) {
	for (int next : tree[cur]) {
		if (next == parent) continue;
		dfs(next, cur);
	}
	dp[cur] = val[cur];
	for (int next : tree[cur]) {
		if (next == parent) continue;
		dp[cur] = max(dp[cur], dp[cur] + dp[next]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	tree.resize(n);
	val.resize(n);
	ind.resize(n);
	dp.assign(n, 0);

	for (int i = 0; i < n - 1; i++) {
		int from, to;
		cin >> from >> to;
		tree[from].push_back(to);
		tree[to].push_back(from);
		ind[to] = 1;
	}
	int root = -1;
	for (int i = 0; i < n; i++) {
		cin >> val[i];
		if (ind[i] == 0) root = i;
	}

	dfs(root, -1);
	cout << dp[root];
}