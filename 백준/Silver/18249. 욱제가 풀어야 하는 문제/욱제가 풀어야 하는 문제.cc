#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <climits>
using namespace std;

int T, n;
int dp[200000];
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 191229; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
	}
	
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n;
		cout << dp[n] << '\n';
	}
}