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

int n;
int dp[101][10][1024];
const int MOD = 1000000000;

int main() {
	cin >> n;
	for (int i = 1; i <= 9; i++) {
		dp[1][i][(1 << i)] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 1023; k++) {
				int mask = k | (1 << j);
				if (j == 0) {
					dp[i][j][mask] = (dp[i][j][mask] + dp[i - 1][j + 1][k]) % MOD;
				}
				else if (j == 9) {
					dp[i][j][mask] = (dp[i][j][mask] + dp[i - 1][j - 1][k]) % MOD;
				}
				else {
					dp[i][j][mask] = (dp[i][j][mask] + dp[i - 1][j - 1][k]) % MOD;
					dp[i][j][mask] = (dp[i][j][mask] + dp[i - 1][j + 1][k]) % MOD;
				}
			}
		}
	}
	long long ret = 0;
	for (int i = 0; i <= 9; i++) {
		ret = (ret + dp[n][i][1023]) % MOD;
	}
	cout << ret;
}