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

int n, m, k;
int sy, sx;
int dy[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int dx[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

ll encode(int y, int x) {
	return 1LL * y * 100001 + x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;
	cin >> sx >> sy;
	cin >> k;

	queue<pair<int,int>> q;
	q.push({ sy, sx });
	
	for (int t = 0; t < k; t++) {
		int sz = q.size();
		unordered_set<ll> visited;

		for (int i = 0; i < sz; i++) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int d = 0; d < 8; d++) {
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (ny < 1 || nx < 1 || ny > n || nx > m) continue;
				if (visited.count(encode(ny, nx))) continue;
				visited.insert(encode(ny, nx));
				q.push({ ny, nx });
			}
		}
	}

	cout << 1LL * n * m - q.size();
}
