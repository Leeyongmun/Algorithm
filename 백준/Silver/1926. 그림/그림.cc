#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>

using namespace std;

int n, m;
int a[501][501];
int cnt = 0;
int ret = 0;
int visited[501][501];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int dfs(int y, int x) {
	visited[y][x] = 1;
	int d = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (visited[ny][nx] || a[ny][nx] == 0) continue;
		d += dfs(ny, nx);
	}
	return d;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1 && !visited[i][j]) {
				ret = max(ret, dfs(i, j));
				cnt++;
			}
		}
	}
	cout << cnt << '\n' << ret;
}