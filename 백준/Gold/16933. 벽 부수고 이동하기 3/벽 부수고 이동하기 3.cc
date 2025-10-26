#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>

using namespace std;

struct Info {
	int y, x, cnt, time;
	Info(int y, int x, int cnt, int time) {
		this->y = y;
		this->x = x;
		this->cnt = cnt;
		this->time = time;
	}
};

int n, m, k;
int a[1001][1001];
int visited[1001][1001][11];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++) {
			a[i][j] = s[j - 1] - '0';
		}
	}
	fill(&visited[0][0][0], &visited[0][0][0] + 1001 * 1001 * 11, -1);
	queue<Info> q;
	q.push(Info(1, 1, 0, 0));
	visited[1][1][0] = 0;
	
	while (!q.empty()) {
		Info cur = q.front();
		q.pop();
		int y = cur.y;
		int x = cur.x;
		int cnt = cur.cnt;
		int time = cur.time;
		if (y == n && x == m) {
			cout << time + 1;
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > n || nx > m) continue;
			if (a[ny][nx] == 0) {
				if (visited[ny][nx][cnt] != -1) continue;
				visited[ny][nx][cnt] = time + 1;
				q.push(Info(ny, nx, cnt, time + 1));
			}
			else {
				if (cnt >= k) continue;
				if (visited[ny][nx][cnt + 1] != -1) continue;
				if (time % 2 == 0) {
					visited[ny][nx][cnt + 1] = time + 1;
					q.push(Info(ny, nx, cnt + 1, time + 1));
				}
				else {
					visited[y][x][cnt] = time + 1;
					q.push(Info(y, x, cnt, time + 1));
				}
			}
		}
	}
	
	cout << -1;
}