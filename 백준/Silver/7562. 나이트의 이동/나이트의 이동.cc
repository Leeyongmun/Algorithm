#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<cmath>

using namespace std;

int T;
int n;
pair<int, int> start, goal;
int dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n;
		cin >> start.first >> start.second;
		cin >> goal.first >> goal.second;
		queue<pair<int, int>> q;
		vector<vector<int>> visited(n, vector<int>(n, 0));
		q.push(start);
		visited[start.first][start.second] = 1;
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			if (y == goal.first && x == goal.second) break;
			for (int i = 0; i < 8; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
				if (visited[ny][nx]) continue;
				q.push({ ny, nx });
				visited[ny][nx] = visited[y][x] + 1;
			}
		}
		cout << visited[goal.first][goal.second] - 1 << '\n';
	}
}