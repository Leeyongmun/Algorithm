#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cstring>
using namespace std;

int n;
int visited[201][201];
int sy, sx, ey, ex;
int dy[] = { -2, -2, 0, 0, 2, 2 };
int dx[] = { -1, 1 ,-2, 2, -1, 1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	cin >> sy >> sx >> ey >> ex;

	queue<pair<int, int>> q;
	fill(&visited[0][0], &visited[0][0] + 201 * 201, -1);
	q.push({ sy, sx });
	visited[sy][sx] = 0;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (y == ey && x == ex) {
			break;
		}
		for (int i = 0; i < 6; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (visited[ny][nx] != -1) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	cout << visited[ey][ex];
}