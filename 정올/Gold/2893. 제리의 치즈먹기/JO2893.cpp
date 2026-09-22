#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include<set>
#include<map>
#include<stack>
#include<cctype>
#include<string>
#include<sstream>
using namespace std;
using ll = long long;

int n, m, k;
char a[1001][1001];
int visited[1001][1001];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
pair<int, int> pos[10];
int sy, sx;

int bfs(int sy, int sx, char target) {
	memset(visited, -1, sizeof(visited));

	queue<pair<int, int>> q;
	q.push({ sy, sx });
	visited[sy][sx] = 0;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (a[y][x] == target) {
			return visited[y][x];
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (a[ny][nx] == 'X' || visited[ny][nx] != -1) continue;
			
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'S') {
				sy = i;
				sx = j;
			}
			else if (a[i][j] >= '1' && a[i][j] <= '9') {
				pos[a[i][j] - '0'] = { i, j };
			}
		}
	}

	int ret = 0;

	for (int i = 1; i <= k; i++) {
		ret += bfs(sy, sx, i + '0');

		sy = pos[i].first;
		sx = pos[i].second;
	}

	cout << ret;
}
