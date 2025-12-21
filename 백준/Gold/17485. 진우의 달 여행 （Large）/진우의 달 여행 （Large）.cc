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
using namespace std;

int n, m;
int a[1001][1001], dp[1001][1001][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	fill(&dp[0][0][0], &dp[0][0][0] + 1001 * 1001 * 3, 987654321);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < 3; j++) {
			dp[1][i][j] = a[1][i];
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j < m) {
				dp[i][j][0] = min(dp[i - 1][j + 1][1], dp[i - 1][j + 1][2]) + a[i][j];
			}
			dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + a[i][j];
			if (j > 1) {
				dp[i][j][2] = min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + a[i][j];
			}
		}
	}
	int ret = 987654321;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < 3; j++) {
			ret = min(dp[n][i][j], ret);
		}
	}
	cout << ret;
}