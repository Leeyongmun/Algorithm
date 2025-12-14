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
using namespace std;

int n, m, t;
vector<tuple<int, int, int>> node;
int parent[10001];

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return false;
	parent[y] = x;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> t;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		node.push_back({c, a, b });
	}

	sort(node.begin(), node.end());

	int ret = 0;
	int cnt = 0;
	for (int i = 0; i < node.size(); i++) {
		int cost = get<0>(node[i]);
		int a = get<1>(node[i]);
		int b = get<2>(node[i]);
		if (merge(a, b)) {
			ret += cost + cnt * t;
			cnt++;
		}
		if (cnt == n - 1) break;
	}
	cout << ret;
	
}