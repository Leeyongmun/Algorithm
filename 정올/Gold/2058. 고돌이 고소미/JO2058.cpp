#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include <set>
#include <map>
#include <stack>
#include <cctype>
#include <string>
using namespace std;
using ll = long long;

int n;
int a[26][26];
bool visited[26][26][26][26];

struct State {
	int ay, ax, by, bx;
	int time;
};

int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0, 0 };
int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1, 0 };

bool valid(int y, int x) {
	if (y < 1 || x < 1 || y > n || x > n) return false;
	if (a[y][x] == 1) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int sy1, sx1, ey1, ex1;
	int sy2, sx2, ey2, ex2;

	cin >> sy1 >> sx1 >> ey1 >> ex1;
	cin >> sy2 >> sx2 >> ey2 >> ex2;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	queue<State> q;
	q.push({ sy1, sx1, sy2, sx2, 0 });
	visited[sy1][sx1][sy2][sx2] = true;

	while (!q.empty()) {
		State cur = q.front();
		q.pop();

		if (cur.ay == ey1 && cur.ax == ex1 && cur.by == ey2 && cur.bx == ex2) {
			cout << cur.time;
			break;
		}

		for (int i = 0; i < 9; i++) {
			int nay = cur.ay + dy[i];
			int nax = cur.ax + dx[i];
			if (!valid(nay, nax)) continue;

			for (int j = 0; j < 9; j++) {
				int nby = cur.by + dy[j];
				int nbx = cur.bx + dx[j];
				if (!valid(nby, nbx)) continue;

				if (abs(nay - nby) <= 1 && abs(nax - nbx) <= 1) continue;
				if (visited[nay][nax][nby][nbx]) continue; 

				visited[nay][nax][nby][nbx] = true;
				q.push({ nay, nax, nby, nbx, cur.time + 1 });
			}
		}
	}
}
