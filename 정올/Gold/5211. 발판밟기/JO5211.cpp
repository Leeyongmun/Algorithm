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
char a[10][10];
int ret[10][10];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
bool isFinish = false;

char nxt(char c) {
	if (c == 'A') return 'B';
	if (c == 'B') return 'C';
	return 'A';
}

bool possibleStart(char start) {
	int need[3] = {};
	char cur = start;

	for (int i = 0; i < n * m; i++) {
		need[cur - 'A']++;
		cur = nxt(cur);
	}

	int have[3] = {};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			have[a[i][j] - 'A']++;
		}
	}

	for (int i = 0; i < 3; i++) {
		if (need[i] != have[i]) return false;
	}

	return true;
}

bool dfs(int y, int x, int cnt) {
	if (cnt == n * m) return true;

	char target = nxt(a[y][x]);

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (ret[ny][nx] != 0) continue;
		if (a[ny][nx] != target) continue;

		ret[ny][nx] = cnt + 1;

		if (dfs(ny, nx, cnt + 1)) return true;

		ret[ny][nx] = 0;
	}

	return false;
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
			if (i != 0 && i != n - 1 && j != 0 && j != m - 1) continue;
			
			if (!possibleStart(a[i][j])) continue;

			ret[i][j] = 1;

			if (dfs(i, j, 1)) {
				for (int k = 0; k < n; k++) {
					for (int l = 0; l < m; l++) {
						cout << ret[k][l] << ' ';
					}
					cout << '\n';
				}
				return 0;
			}

			ret[i][j] = 0;
		}
	}

	cout << "impossible\n";
}
