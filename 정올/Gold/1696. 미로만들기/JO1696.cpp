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
int a[51][51];
int visited[51][51];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			a[i][j] = s[j] - '0';
		}
	}

	fill(&visited[0][0], &visited[0][0] + 51 * 51, 987654321);

	deque<pair<int, int>> q;

	visited[0][0] = 0;
	q.push_front({ 0, 0 });

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop_front();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

			int cost = (a[ny][nx] == 0 ? 1 : 0);

			if (visited[ny][nx] > visited[y][x] + cost) {
				visited[ny][nx] = visited[y][x] + cost;

				if (cost == 0) {
					q.push_front({ ny, nx });
				}
				else {
					q.push_back({ ny, nx });
				}
			}
		}
	}

	cout << visited[n - 1][n - 1];
}
