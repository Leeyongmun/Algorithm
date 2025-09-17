#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<string>
#include<cstring>
using namespace std;

int n, m;
int a[10][10];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<vector<vector<int>>> dir = {
	{},
	{{0}, {1}, {2}, {3}},
	{{0, 2}, {1, 3}},
	{{0, 1}, {1, 2}, {2, 3}, {3, 0}},
	{{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}},
	{{0, 1, 2, 3}}
};
vector<pair<int, int>> v;
int ret = 987654321;

void watch(int y, int x, int d, int map[][10]) {
	int ny = y + dy[d];
	int nx = x + dx[d];
	while (ny >= 0 && nx >= 0 && ny < n && nx < m && map[ny][nx] != 6) {
		if (map[ny][nx] == 0) map[ny][nx] = 9;
		ny += dy[d];
		nx += dx[d];
	}
}

void solve(int cnt, int map[][10]) {
	if (cnt == v.size()) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0) sum++;
			}
		}
		ret = min(sum, ret);
		return;
	}
	int y = v[cnt].first;
	int x = v[cnt].second;
	int t = a[y][x];
	int backup[10][10];
	memcpy(backup, map, sizeof(int) * 10 * 10);
	for (auto dirs : dir[t]) {
		memcpy(map, backup, sizeof(int) * 10 * 10);
		for (int d : dirs) watch(y, x, d, map);
		solve(cnt + 1, map);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] != 0 && a[i][j] != 6) {
				v.push_back({ i, j });
			}
		}
	}
	solve(0, a);
	cout << ret;
}