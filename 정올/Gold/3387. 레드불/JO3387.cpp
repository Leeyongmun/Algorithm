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

const long long MOD = 1000000007;
int n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	vector<long long> dp(n + 1, 0);

	dp[0] = 1;
	int x = 1;

	for (int i = 1; i <= n; i++) {
		dp[i] = x;

		x = (x + dp[i]) % MOD;

		if (i - k >= 0) {
			x = (x - dp[i - k] + MOD) % MOD;
		}
	}

	cout << dp[n] % MOD;
}
