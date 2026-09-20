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

int n;
char a[51][51];
char ret[51][51];
bool visited[51][51];
int sy, sx, ey, ex;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void bfs(int cy, int cx) {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({ sy, sx });
	visited[sy][sx] = true;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (y == ey && x == ex) {
			return;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (a[ny][nx] == '#' || visited[ny][nx]) continue;
			q.push({ ny, nx });
			visited[ny][nx] = true;
		}
	}

	ret[cy][cx] = 'o';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'S') {
				sy = i;
				sx = j;
			}
			else if (a[i][j] == 'E') {
				ey = i;
				ex = j;
			}
		}
	}

	memcpy(ret, a, sizeof(a));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == '.') {
				a[i][j] = '#';
				bfs(i, j);
				a[i][j] = '.';
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ret[i][j];
		}
		cout << '\n';
	}
}
