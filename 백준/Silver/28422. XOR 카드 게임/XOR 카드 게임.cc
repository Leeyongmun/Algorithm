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
int a[100001], dp[100001];

int bitcount(unsigned int x) {
	int cnt = 0;
	while (x) {
		x &= (x - 1);
		cnt++;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << 0;
		return 0;
	}
	dp[0] = dp[1] = -987654321;
	dp[2] = bitcount(a[1] ^ a[2]);
	dp[3] = bitcount(a[1] ^ a[2] ^ a[3]);

	for (int i = 4; i <= n; i++) {
		dp[i] = max(dp[i - 2] + bitcount(a[i - 1] ^ a[i]), dp[i - 3] + bitcount(a[i - 2] ^ a[i - 1] ^ a[i]));
	}
	cout << dp[n];
}