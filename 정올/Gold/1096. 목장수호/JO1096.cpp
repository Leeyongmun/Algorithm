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
int a[701][701];
bool check[701][701];
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int ret = 0;

bool bfs(int y, int x) {
	queue<pair<int, int>> q;
	bool isPeak = true;
	q.push({ y, x });
	check[y][x] = true;
	int cur = a[y][x];

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (a[ny][nx] > cur) isPeak = false;
			if (check[ny][nx]) continue;
			if (a[ny][nx] == cur) {
				check[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}

	return isPeak;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!check[i][j]) {
				if (bfs(i, j)) {
					ret++;
				}
			}
		}
	}

	cout << ret;
}
