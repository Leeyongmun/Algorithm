#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<cmath>

using namespace std;

int n;
int dp[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1]) % 15746;
	}
	cout << dp[n];
}