#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
vector<vector<int>> dist;

int main() {
	cin >> n >> m;
	dist.assign(n + 1, vector<int>(n + 1, 987654321));
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
	}
	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int ret = 987654321;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			ret = min(ret, dist[i][j] + dist[j][i]);
		}
	}
	cout << ((ret == 987654321) ? -1 : ret);
}