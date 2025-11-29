#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<string>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cmath>

using namespace std;

int n, m;
char a[11][11];
pair<int, int> blue, red;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

pair<int,int> move(pair<int, int> cur, int dir) {
	int y = cur.first;
	int x = cur.second;
	int ny = y;
	int nx = x;
	while (true) {
		ny += dy[dir];
		nx += dx[dir];
		if (a[ny][nx] == '#') {
			return { ny - dy[dir], nx - dx[dir]};
		}
		if (a[ny][nx] == 'O') {
			return { ny, nx };
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];
			if (a[i][j] == 'B') {
				blue = { i, j };
				a[i][j] = '.';
			}
			else if (a[i][j] == 'R') {
				red = { i, j };
				a[i][j] = '.';
			}
		}
	}

	queue < pair<pair<int, int>, pair<int, int>>> q;
	q.push({ red, blue });
	int t = 0;
	while (!q.empty()) {
		t++;
		if (t > 10) {
			cout << -1;
			return 0;
		}
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			pair<int, int> r = q.front().first;
			pair<int, int> b = q.front().second;
			q.pop();
			for (int d = 0; d < 4; d++) {
				pair<int, int> nr = move(r, d);
				pair<int, int> nb = move(b, d);
				if (nr == nb && a[nr.first][nr.second] == 'O') continue;
				if (nr == nb) {
					if (d == 0) {
						if (r.first < b.first) {
							nb = { nb.first + 1, nb.second };
						}
						else {
							nr = { nr.first + 1, nr.second };
						}
					}
					else if (d == 1) {
						if (r.second > b.second) {
							nb = { nb.first, nb.second - 1 };
						}
						else {
							nr = { nr.first, nr.second - 1 };
						}
					}
					else if (d == 2) {
						if (r.first < b.first) {
							nr = { nr.first - 1, nr.second };
						}
						else {
							nb = { nb.first - 1, nb.second };
						}
					}
					else {
						if (r.second > b.second) {
							nr = { nr.first, nr.second + 1 };
						}
						else {
							nb = { nb.first, nb.second + 1 };
						}
					}
				}
				if (a[nb.first][nb.second] == 'O') continue;
				if (a[nr.first][nr.second] == 'O') {
					cout << t;
					return 0;
				}
				q.push({ nr, nb });
			}
		}
	}

}