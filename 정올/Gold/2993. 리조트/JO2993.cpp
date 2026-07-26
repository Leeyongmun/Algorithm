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

int n, m;
int a[101], dp[101][41];
bool closed[101];

int solve(int d, int c) {
	if (d > n) return 0;
	
	if (dp[d][c] != -1) return dp[d][c];

	if (closed[d]) {
		return dp[d][c] = solve(d + 1, c);
	}

	dp[d][c] = 987654321;

	dp[d][c] = min(dp[d][c], solve(d + 1, c) + 10000);
	dp[d][c] = min(dp[d][c], solve(d + 3, c + 1) + 25000);
	dp[d][c] = min(dp[d][c], solve(d + 5, c + 2) + 37000);

	if (c >= 3) {
		dp[d][c] = min(dp[d][c], solve(d + 1, c - 3));
	}

	return dp[d][c];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		closed[x] = true;
	}

	memset(dp, -1, sizeof(dp));

	cout << solve(1, 0);
}
