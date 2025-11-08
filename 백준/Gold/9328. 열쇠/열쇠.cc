#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<deque>
#include<queue>
#include<string>

using namespace std;

int T;
int n, m;
char a[102][102];
int visited[102][102];
vector<pair<int, int>> v;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int key = 0;

void init() {
	fill(&visited[0][0], &visited[0][0] + 102 * 102, 0);
	fill(&a[0][0], &a[0][0] + 102 * 102, '.');
	key = 0;
}

int bfs() {
	queue<pair<int, int>> q;
	queue<pair<int, int>> door[26];
	visited[0][0] = 1;
	q.push({ 0, 0 });
	int cnt = 0;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n + 2 || nx >= m + 2) continue;
			if (a[ny][nx] == '*' || visited[ny][nx]) continue;
			if (a[ny][nx] >= 'a' && a[ny][nx] <= 'z') {
				int k = a[ny][nx] - 'a';
				key |= (1 << k);
				while (!door[k].empty()) {
					int ty = door[k].front().first;
					int tx = door[k].front().second;
					q.push({ty, tx});
					visited[ty][tx] = 1;
					door[k].pop();
				}
			}
			if (a[ny][nx] >= 'A' && a[ny][nx] <= 'Z') {
				int k = a[ny][nx] - 'A';
				if (!(key & (1 << k))) {
					door[k].push({ ny, nx });
					continue;
				}
			}
			if (a[ny][nx] == '$') cnt++;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> a[i][j];
			}
		}
		string s;
		cin >> s;
		if (s[0] != '0') {
			for (int i = 0; i < s.size(); i++) {
				key |= (1 << (s[i] - 'a'));
			}
		}
		cout << bfs() << '\n';
	}
}