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
vector<int> v1[501];
vector<int> v2[501];
int visited[501];

int dfs(vector<int> v[], int cur) {
	int cnt = 0;
	visited[cur] = 1;
	for (int next : v[cur]) {
		if (visited[next]) continue;
		cnt += dfs(v, next) + 1;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v1[a].push_back(b);
		v2[b].push_back(a);
	}
	int ret = 0;

	for (int i = 1; i <= n; i++) {
		fill(visited, visited + 501, 0);
		int a = dfs(v1, i);
		fill(visited, visited + 501, 0);
		int b = dfs(v2, i);
		if (a + b == n - 1) ret++;
	}
	cout << ret;
}
