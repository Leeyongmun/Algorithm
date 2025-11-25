#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<string>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cmath>

using namespace std;

int n, m, k;
int a[101][101];
int visited[101][101];
int ret = 0;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int dfs(int y, int x) {
	visited[y][x] = 1;
	int cnt = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 1 || nx < 1 || ny > n || nx > m) continue;
		if (visited[ny][nx] || !a[ny][nx]) continue;
		cnt += dfs(ny, nx);
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int r, c;
		cin >> r >> c;
		a[r][c] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 1 && !visited[i][j]) {
				ret = max(ret, dfs(i, j));
			}
		}
	}
	cout << ret;
}