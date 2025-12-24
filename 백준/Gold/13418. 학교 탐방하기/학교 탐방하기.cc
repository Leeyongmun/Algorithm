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
using namespace std;

int n, m;
int parent[1001];
vector<tuple<int, int, int>> graph;

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

	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m + 1; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		if (cost == 0) cost = 1;
		else cost = 0;
		graph.push_back({ cost, from, to });
	}

	sort(graph.rbegin(), graph.rend());

	int cnt = 0;
	int best = 0;
	for (int i = 0; i < m + 1; i++) {
		int a = get<1>(graph[i]);
		int b = get<2>(graph[i]);
		int flag = get<0>(graph[i]);
		if (merge(a, b)) {
			best += flag;
			cnt++;
		}
		if(cnt == n) break;
	}
	best *= best;

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	cnt = 0;
	int worst = 0;
	sort(graph.begin(), graph.end());
	for (int i = 0; i < m + 1; i++) {
		int a = get<1>(graph[i]);
		int b = get<2>(graph[i]);
		int flag = get<0>(graph[i]);
		if (merge(a, b)) {
			worst += flag;
			cnt++;
		}
		if (cnt == n) break;
	}
	worst *= worst;
	cout << best - worst;
}