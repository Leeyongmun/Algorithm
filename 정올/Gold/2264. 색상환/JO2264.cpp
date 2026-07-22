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

const int MOD = 1000000003;

int n, k;
int dp[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	if (k > n / 2) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			if (j > (i + 1) / 2) break;
			dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % MOD;
		}
	}

	cout << (dp[n - 3][k - 1] + dp[n - 1][k]) % MOD;
}
