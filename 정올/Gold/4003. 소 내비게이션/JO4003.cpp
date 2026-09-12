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
char a[21][21];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int visited[1601][1601];

int encode(int y, int x, int d) {
	return (y * n + x) * 4 + d;
}

void go(int& y, int& x, int d) {
	if (y == 0 && x == n - 1) return;
	int ny = y + dy[d];
	int nx = x + dx[d];

	if (ny < 0 || nx < 0 || ny >= n || nx >= n) return;
	if (a[ny][nx] == 'H') return;

	y = ny;
	x = nx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			a[i][j] = s[j];
		}
	}

	memset(visited, -1, sizeof(visited));

	queue<pair<int, int>> q;
	int id1 = encode(n - 1, 0, 0);
	int id2 = encode(n - 1, 0, 1);
	visited[id1][id2] = 0;
	q.push({ id1, id2 });

	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		id1 = p.first;
		id2 = p.second;

		int dist = visited[id1][id2];

		int ad = id1 % 4;
		int bd = id2 % 4;
		id1 /= 4;
		id2 /= 4;

		int ax = id1 % n;
		int bx = id2 % n;
		id1 /= n;
		id2 /= n;

		int ay = id1;
		int by = id2;

		if (ay == 0 && ax == n - 1 && by == 0 && bx == n - 1) {
			cout << dist;
			break;
		}

		{
			int nay = ay, nax = ax;
			int nby = by, nbx = bx;

			go(nay, nax, ad);
			go(nby, nbx, bd);

			int nid1 = encode(nay, nax, ad);
			int nid2 = encode(nby, nbx, bd);

			if (visited[nid1][nid2] == -1) {
				visited[nid1][nid2] = dist + 1;
				q.push({ nid1, nid2 });
			}
		}

		{
			int nad = ad;
			int nbd = bd;

			if (!(ay == 0 && ax == n - 1)) nad = (ad + 3) % 4;
			if (!(by == 0 && bx == n - 1)) nbd = (bd + 3) % 4;

			int nid1 = encode(ay, ax, nad);
			int nid2 = encode(by, bx, nbd);

			if (visited[nid1][nid2] == -1) {
				visited[nid1][nid2] = dist + 1;
				q.push({ nid1, nid2 });
			}
		}

		{
			int nad = ad;
			int nbd = bd;

			if (!(ay == 0 && ax == n - 1)) nad = (ad + 1) % 4;
			if (!(by == 0 && bx == n - 1)) nbd = (bd + 1) % 4;

			int nid1 = encode(ay, ax, nad);
			int nid2 = encode(by, bx, nbd);

			if (visited[nid1][nid2] == -1) {
				visited[nid1][nid2] = dist + 1;
				q.push({ nid1, nid2 });
			}
		}
	}
}
