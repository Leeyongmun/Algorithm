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
using namespace std;

int n;
int ey, ex;
int a[101][101];
int dist[101][101];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

struct State {
	int y, x, c;

	bool operator > (const State& other) const {
		return c > other.c;
	}
};

priority_queue<State, vector<State>, greater<>> pq;

int main() {
	cin >> n;
	cin >> ey >> ex;
	fill(&dist[0][0], &dist[0][0] + 101 * 101, 987654321);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (i == 1 || i == n || j == 1 || j == n) {
				pq.push({i, j, a[i][j] * a[i][j]});
				dist[i][j] = a[i][j] * a[i][j];
			}
		}
	}

	while (!pq.empty()) {
		State now = pq.top();
		int y = now.y;
		int x = now.x;
		int cost = now.c;
		pq.pop();

		if (y == ey && x == ex) {
			cout << dist[y][x];
			break;
		}

		if (dist[y][x] < cost) continue;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > n || nx > n) continue;
			int ncost = cost;
			if (a[ny][nx] > a[y][x]) {
				ncost += (a[ny][nx] - a[y][x]) * (a[ny][nx] - a[y][x]);
			}
			else if (a[ny][nx] < a[y][x]) {
				ncost += a[y][x] - a[ny][nx];
			}
			if (dist[ny][nx] > ncost) {
				dist[ny][nx] = ncost;
				pq.push({ny, nx, ncost});
			}
		}
	}
}
