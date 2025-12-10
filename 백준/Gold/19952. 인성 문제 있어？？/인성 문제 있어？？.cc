#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

int T;
int n, m, o, f, sy, sx, gy, gx;
int a[101][101];
int visited[101][101];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void init() {
	fill(&a[0][0], &a[0][0] + 101 * 101, 0);
	fill(&visited[0][0], &visited[0][0] + 101 * 101, -1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		cin >> n >> m >> o >> f >> sy >> sx >> gy >> gx;
		for (int i = 0; i < o; i++) {
			int y, x, h;
			cin >> y >> x >> h;
			a[y][x] = h;
		}
		bool flag = false;
		queue<pair<int, int>> q;
		q.push({ sy, sx });
		visited[sy][sx] = f;
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			int cf = visited[y][x];
			if (y == gy && x == gx) {
				flag = true;
				break;
			}
			if (cf == 0) continue;
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny <= 0 || nx <= 0 || ny > n || nx > m) continue;
				if (a[ny][nx] - a[y][x] > cf) continue;
				if (visited[ny][nx] < visited[y][x] - 1) {
					q.push({ ny, nx });
					visited[ny][nx] = visited[y][x] - 1;
				}
			}
		}
		if (flag) cout << "잘했어!!\n";
		else cout << "인성 문제있어??\n";
	}
	
}