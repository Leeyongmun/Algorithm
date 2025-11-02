#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<string>
#include<cmath>
#include<set>
#include<queue>

using namespace std;

int n, m, k;
char c;
char a[31][31][31];
int visited[31][31][31];
int dz[] = { 0, 0, 0, 0, 1, -1 };
int dy[] = { -1, 0, 1, 0, 0, 0 };
int dx[] = { 0, 1, 0, -1, 0, 0 };
tuple<int, int, int> start, goal;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (true) {
		fill(&visited[0][0][0], &visited[0][0][0] + 31 * 31 * 31, 0);
		cin >> n >> m >> k;

		if (n == 0 && m == 0 && k == 0) return 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int l = 0; l < k; l++) {
					cin >> a[i][j][l];
					if (a[i][j][l] == 'S') start = { i, j, l };
					else if (a[i][j][l] == 'E') goal = { i, j, l };
				}
			}
		}

		queue<tuple<int, int, int>> q;
		q.push(start);
		visited[get<0>(start)][get<1>(start)][get<2>(start)] = 1;
		while (!q.empty()) {
			int z = get<0>(q.front());
			int y = get<1>(q.front());
			int x = get<2>(q.front());
			if (a[z][y][x] == 'e') break;
			q.pop();
			for (int i = 0; i < 6; i++) {
				int nz = z + dz[i];
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (nz < 0 || ny < 0 || nx < 0 || nz >= n || ny >= m || nx >= k) continue;
				if (visited[nz][ny][nx] != 0 || a[nz][ny][nx] == '#') continue;
				visited[nz][ny][nx] = visited[z][y][x] + 1;
				q.push({ nz, ny, nx });
			}
		}
		int dist = visited[get<0>(goal)][get<1>(goal)][get<2>(goal)];
		if (dist == 0) cout << "Trapped!" << '\n';
		else cout << "Escaped in " << dist - 1 << " minute(s).\n";
	}
}