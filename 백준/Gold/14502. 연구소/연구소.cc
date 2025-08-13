#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;

int n, m;
int a[9][9];
int tmp[9][9];
vector<pair<int, int>> blank, virus;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int ret = 0;

void dfs(int y, int x) {
	tmp[y][x] = 2;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (tmp[ny][nx] != 0) continue;
		dfs(ny, nx);
	}
}

void solve(int now, int cnt) {
	if (cnt == 3) {
		int sum = 0;
		copy(&a[0][0], &a[0][0] + 9 * 9, &tmp[0][0]);
		for (pair<int, int> p : virus) {
			int y = p.first;
			int x = p.second;
			dfs(y, x);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (tmp[i][j] == 0) {
					sum++;
				}
			}
		}
		ret = max(ret, sum);
		return;
	}
	for (int i = now; i < blank.size(); i++) {
		int y = blank[i].first;
		int x = blank[i].second;
		a[y][x] = 1;
		solve(i + 1, cnt + 1);
		a[y][x] = 0;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) {
				blank.push_back({ i, j });
			}
			else if (a[i][j] == 2) {
				virus.push_back({ i, j });
			}
		}
	}
	solve(0, 0);
	cout << ret;
}
