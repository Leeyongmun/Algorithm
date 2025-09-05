#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <map>
#include <sstream>
#include <unordered_map>
using namespace std;

int n, m;
int a[1001][1001];
int visited[1001][1001][2];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int ret = 987654321;

int bfs() {
	queue<tuple<int, int, int>> q;
	q.push({ 0, 0, 0 });
	visited[0][0][0] = 1;
	while (q.size()) {
		int y = get<0>(q.front());
		int x = get<1>(q.front());
		int broke = get<2>(q.front());
		q.pop();

		if (y == n - 1 && x == m - 1) return visited[y][x][broke];

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

			if (a[ny][nx] == 0 && visited[ny][nx][broke] == 0) {
				visited[ny][nx][broke] = visited[y][x][broke] + 1;
				q.push({ ny, nx, broke });
			}

			if (a[ny][nx] == 1 && broke == 0 && visited[ny][nx][1] == 0) {
				visited[ny][nx][1] = visited[y][x][broke] + 1;
				q.push({ ny, nx, 1 });
			}
		}
	}
	return -1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < m; j++) {
			a[i][j] = row[j] - '0';
		}
	}
	cout << bfs();
	return 0;
}