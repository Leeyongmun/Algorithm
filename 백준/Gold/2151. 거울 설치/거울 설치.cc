#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<deque>
#include<queue>
#include<string>

using namespace std;

int n;
char a[51][51];
int visited[51][51][4];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int idx1[] = { 1, 0, 3, 2 };
int idx2[] = { 3, 2, 1, 0 };
vector<pair<int, int>> mirror;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == '#') {
				mirror.push_back({ i, j });
			}
		}
	}
	fill(&visited[0][0][0], &visited[0][0][0] + 51 * 51 * 4, 987654321);
	deque<tuple<int, int, int>> dq;
	int sy = mirror[0].first;
	int sx = mirror[0].second;
	for (int i = 0; i < 4; i++) {
		visited[sy][sx][i] = 0;
		dq.push_back({ sy, sx, i });
	}
	while (!dq.empty()) {
		int y = get<0>(dq.front());
		int x = get<1>(dq.front());
		int dir = get<2>(dq.front());
		dq.pop_front();
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (a[ny][nx] == '*') continue;
		if (visited[ny][nx][dir] > visited[y][x][dir]) {
			visited[ny][nx][dir] = visited[y][x][dir];
			dq.push_front({ ny, nx, dir });
		}
		if (a[ny][nx] == '!') {
			int nd = idx1[dir];
			if (visited[ny][nx][nd] > visited[y][x][dir] + 1) {
				visited[ny][nx][nd] = visited[y][x][dir] + 1;
				dq.push_back({ ny, nx, nd });
			}
			nd = idx2[dir];
			if (visited[ny][nx][nd] > visited[y][x][dir] + 1) {
				visited[ny][nx][nd] = visited[y][x][dir] + 1;
				dq.push_back({ ny, nx, nd });
			}
		}
	}
	int gy = mirror[1].first;
	int gx = mirror[1].second;
	int ret = 987654321;
	for (int i = 0; i < 4; i++) {
		ret = min(ret, visited[gy][gx][i]);
	}
	cout << ret;
}