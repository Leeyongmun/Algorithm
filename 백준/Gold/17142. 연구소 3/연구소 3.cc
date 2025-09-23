#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int n, m;
int ret = 987654321;
vector<vector<int>> v;
vector<pair<int, int>> virus;
vector<pair<int, int>> active;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int simulation() {
	int time = 0;
	vector<vector<int>> visited(n, vector<int>(n, -1));
	queue<pair<int, int>> q;
	for (auto p : active) {
		q.push(p);
		visited[p.first][p.second] = 0;
	}

	int count = 0;
	int zero = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] == 0) zero++;
		}
	}

	if (zero == 0) return 0;
	
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (visited[ny][nx] != -1) continue;
			if (v[ny][nx] == 1) continue;
			q.push({ ny, nx });
			visited[ny][nx] = visited[y][x] + 1;
			if (v[ny][nx] == 0) {
				count++;
				if (count == zero) return visited[ny][nx];
			}
		}
	}
	return 987654321;
}

void solve(int now, int cnt) {
	if (cnt == m) {
		ret = min(ret,simulation());
		return;
	}
	for (int i = now; i < virus.size(); i++) {
		active.push_back(virus[i]);
		solve(i + 1, cnt + 1);
		active.pop_back();
	}
}

int main() {
	cin >> n >> m;
	v.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
			if (v[i][j] == 2) {
				virus.push_back({ i, j });
			}
		}
	}
	solve(0, 0);
	cout << ((ret == 987654321) ? -1 : ret);
}