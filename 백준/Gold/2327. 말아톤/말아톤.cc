#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cstring>
using namespace std;

int n, m;
int h[351], s[351];
int dp[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		cin >> h[i] >> s[i];
	}

	memset(dp, -1, sizeof(dp));
	dp[0] = 987654321;

	for (int i = 0; i < n; i++) {
		for (int j = m; j >= h[i]; j--) {
			if (dp[j - h[i]] != -1) {
				dp[j] = max(dp[j], min(dp[j - h[i]], s[i]));
			}
		}
	}
	cout << dp[m];
}