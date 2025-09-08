#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
using namespace std;

int n, k;
int w[1001], t[1001];
vector<int> dp[1001];

int main() {
	cin >> n >> k;
	for (int i = 0; i < 1001; i++) {
		dp[i].resize(n + 1);
	}
	for (int i = 1; i <= k; i++) {
		cin >> w[i] >> t[i];
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= t[i]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - t[i]] + w[i]);
			}
		}
	}
	cout << *max_element(dp[k].begin(), dp[k].end());
}