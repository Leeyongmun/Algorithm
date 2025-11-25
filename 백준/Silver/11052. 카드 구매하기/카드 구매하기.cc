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
int a[1001];
int dp[1001];

int main() {
	ios::sync_with_stdio;
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[1] = a[1];
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			dp[i] = max(dp[i], dp[j] + a[i - j]);
		}
	}
	cout << dp[n];
}