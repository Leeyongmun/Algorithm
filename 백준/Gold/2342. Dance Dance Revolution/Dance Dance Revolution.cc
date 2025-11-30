#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<string>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
using namespace std;

int dp[100001][5][5];
int ret = 987654321;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(&dp[0][0][0], &dp[0][0][0] + 100001 * 5 * 5, 987654321);
	dp[0][0][0] = 0;
	for (int t = 1; ; t++) {
		int n;
		cin >> n;
		if (n == 0) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					ret = min(dp[t - 1][i][j], ret);
				}
			}
			break;
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (j == 0) {
					dp[t][n][i] = min(dp[t - 1][j][i] + 2, dp[t][n][i]);
					dp[t][i][n] = min(dp[t - 1][i][j] + 2, dp[t][i][n]);
				}
				if (j == n) {
					dp[t][n][i] = min(dp[t - 1][j][i] + 1, dp[t][n][i]);
					dp[t][i][n] = min(dp[t - 1][i][j] + 1, dp[t][i][n]);
				}
				if (abs(j - n) == 2) {
					dp[t][n][i] = min(dp[t - 1][j][i] + 4, dp[t][n][i]);
					dp[t][i][n] = min(dp[t - 1][i][j] + 4, dp[t][i][n]);
				}
				else {
					dp[t][n][i] = min(dp[t - 1][j][i] + 3, dp[t][n][i]);
					dp[t][i][n] = min(dp[t - 1][i][j] + 3, dp[t][i][n]);
				}
			}
		}
	}
	cout << ret;
}