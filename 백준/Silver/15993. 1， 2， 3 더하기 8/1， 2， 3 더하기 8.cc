#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

int T;
int dp[100001][2];
const int MOD = 1000000009;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[0][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= 100000; i++) {
		dp[i][0] = (dp[i][0] + dp[i - 1][1]) % MOD;
		dp[i][1] = (dp[i][1] + dp[i - 1][0]) % MOD;
		dp[i][0] = (dp[i][0] + dp[i - 2][1]) % MOD;
		dp[i][1] = (dp[i][1] + dp[i - 2][0]) % MOD;
		if (i != 2) {
			dp[i][0] = (dp[i][0] + dp[i - 3][1]) % MOD;
			dp[i][1] = (dp[i][1] + dp[i - 3][0]) % MOD;
		}
	}

	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n;
		cin >> n;
		cout << dp[n][1] << ' ' << dp[n][0] << '\n';
	}
}