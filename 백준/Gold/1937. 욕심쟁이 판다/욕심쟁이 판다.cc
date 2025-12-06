#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n;
int a[501][501], dp[501][501];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int ret = 0;

int dfs(int y, int x) {
	if (dp[y][x] != -1) return dp[y][x];
	dp[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (a[y][x] < a[ny][nx]) {
			dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
		}
	}
	return dp[y][x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	fill(&dp[0][0], &dp[0][0] + 501 * 501, -1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == -1) {
				ret = max(ret, dfs(i, j));
			}
		}
	}
	cout << ret;
}