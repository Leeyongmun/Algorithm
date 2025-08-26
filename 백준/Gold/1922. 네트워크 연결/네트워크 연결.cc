#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;

int n, m;
vector<tuple<int, int, int>> edge;
int parent[1001];

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return false;
	parent[x] = y;
	return true;
}

int main() {
	cin >> n >> m;
	edge.resize(m);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		edge.push_back({ cost, from, to });
	}
	sort(edge.begin(), edge.end());
	int cnt = 0;
	long long ret = 0;
	for (auto e : edge) {
		int cost = get<0>(e);
		int from = get<1>(e);
		int to = get<2>(e);
		if (!merge(from, to)) continue;
		cnt++;
		ret += cost;
		if (cnt == n - 1) break;
	}
	cout << ret;
}