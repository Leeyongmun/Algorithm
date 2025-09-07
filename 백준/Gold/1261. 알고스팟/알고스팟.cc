#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
using namespace std;

int n, m;
int a[101][101];
int visited[101][101];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	fill(&visited[0][0], &visited[0][0] + 101 * 101, 987654321);
	deque<pair<int, int>> dq;
	dq.push_front({ 0, 0 });
	visited[0][0] = 0;
	while (!dq.empty()) {
		int y = dq.front().first;
		int x = dq.front().second;
		dq.pop_front();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (a[ny][nx] == 0) {
				if (visited[ny][nx] > visited[y][x]) {
					visited[ny][nx] = visited[y][x];
					dq.push_front({ ny, nx });
				}
			}
			else {
				if (visited[ny][nx] > visited[y][x] + 1) {
					visited[ny][nx] = visited[y][x] + 1;
					dq.push_back({ ny, nx });
				}
			}
		}
	}
	cout << visited[n - 1][m - 1];
}