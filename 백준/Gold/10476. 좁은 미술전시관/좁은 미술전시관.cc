#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

int n, k;
int a[201][2];
int dp[201][201][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k;
	for (int i = 0; i < n + 1; i++) {
		cin >> a[i][0] >> a[i][1];
	}

	fill(&dp[0][0][0], &dp[0][0][0] + 201 * 201 * 3, -987654321);

	dp[0][0][0] = a[0][0] + a[0][1];
	dp[0][1][1] = a[0][1];
	dp[0][1][2] = a[0][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i][j][0] = max(dp[i - 1][j][0], max(dp[i - 1][j][1], dp[i - 1][j][2])) + a[i][0] + a[i][1];
			dp[i][j + 1][1] = max(dp[i - 1][j][0], dp[i - 1][j][1]) + a[i][1];
			dp[i][j + 1][2] = max(dp[i - 1][j][0], dp[i - 1][j][2]) + a[i][0];
		}
	}
	cout << max(dp[n - 1][k][0], max(dp[n - 1][k][1], dp[n - 1][k][2]));
}