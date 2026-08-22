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

char a[5][5];
int ret = 0;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

bool isPossible(int mask) {
	int check[5][5] = {};
	bool visited[5][5] = {};
	int y, x;

	for (int i = 0; i < 25; i++) {
		if (mask & (1 << i)) {
			y = i / 5;
			x = i % 5;
			check[y][x] = 1;
		}
	}

	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = 1;
	int cnt_o = a[y][x] == 'O' ? 1 : 0;
	int cnt = 1;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
			if (visited[ny][nx] || !check[ny][nx]) continue;
			if (a[ny][nx] == 'O') cnt_o++;
			cnt++;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}

	if (cnt_o >= 4 && cnt == 7) return true;
	return false;
}

void comb(int idx, int cnt, int mask) {
	if (cnt == 7) {
		if (isPossible(mask)) ret++;
		return;
	}

	if (25 - idx < 7 - cnt) return;

	for (int i = idx; i < 25; i++) {
		comb(i + 1, cnt + 1, mask | (1 << i));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
		}
	}

	comb(0, 0, 0);

	cout << ret;
}
