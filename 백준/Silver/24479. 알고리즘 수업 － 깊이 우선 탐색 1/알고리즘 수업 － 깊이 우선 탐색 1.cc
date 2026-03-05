#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

int n, m, r;
set<int> graph[100001];
int visited[100001];
int cnt = 1;

void dfs(int cur) {
	visited[cur] = cnt++;
	
	for (int next : graph[cur]) {
		if (visited[next]) continue;
		dfs(next);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> r;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].insert(b);
		graph[b].insert(a);
	}

	dfs(r);
	for (int i = 1; i <= n; i++) {
		cout << visited[i] << '\n';
	}
}
