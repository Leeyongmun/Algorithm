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
int dp[1001][10];

int main() {
	cin >> n;
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 9; j >= 0; j--) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < 10; i++) {
		ret = (ret + dp[n][i]) % 10007;
	}
	cout << ret;
}