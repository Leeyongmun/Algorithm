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
using ll = long long;

int n, m;
int a[31][31], b[31][31];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int visited[31][31];

void bfs(int sy, int sx, int vac) {
	queue<pair<int, int>> q;
	int target = a[sy][sx];
	q.push({ sy, sx });
	visited[sy][sx] = 1;
	
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		a[y][x] = vac;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx]) continue;
			if (a[ny][nx] == target) {
				q.push({ ny, nx });
				visited[ny][nx] = 1;
			}
		}
	}
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
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		bool flag = false;
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				bfs(i, j, b[i][j]);
				flag = true;
				break;
			}
		}
		if (flag) break;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				cout << "NO";
				return 0;
			}
		}
	}

	cout << "YES";
}
