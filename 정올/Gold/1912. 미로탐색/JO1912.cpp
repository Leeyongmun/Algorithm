#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include <set>
#include <map>
#include <stack>
#include <cctype>
#include <string>
using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> graph;
vector<int> ret;
vector<bool> visited;

void dfs(int cur, int parent) {
	visited[cur] = true;
	ret.push_back(cur);

	for (int next : graph[cur]) {
		if (next == parent) continue;
		if (visited[next]) continue;
		dfs(next, cur);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	graph.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(1, -1);

	for (int x : ret) {
		cout << x << ' ';
	}
}
