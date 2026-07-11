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
using namespace std;

int n, m;
vector<int> graph[3001];
bool visited[3001];
vector<int> path;

void dfs(int cur) {
	visited[cur] = true;

	for (int next : graph[cur]) {
		if (visited[next]) continue;
		path.push_back(next);
		dfs(next);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	path.push_back(1);
	dfs(1);

	for (int x : path) {
		cout << x << ' ';
	}
}
