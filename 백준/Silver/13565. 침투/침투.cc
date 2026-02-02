#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <climits>
using namespace std;

int n, m;
int a[1001][1001];
vector<pair<int, int>> v;
int visited[1001][1001];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j] - '0';
			if (a[i][j] == 0 && i == 0) v.push_back({ i, j });
		}
	}

	queue<pair<int, int>> q;
	for (auto p : v) {
		q.push(p);
		visited[p.first][p.second] = 1;
	}
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (y == n - 1) {
			cout << "YES";
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx] || a[ny][nx]) continue;
			q.push({ ny, nx });
			visited[ny][nx] = 1;
		}
	}

	cout << "NO";
}