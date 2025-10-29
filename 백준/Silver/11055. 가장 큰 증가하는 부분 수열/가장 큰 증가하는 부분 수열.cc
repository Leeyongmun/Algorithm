#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<deque>
#include<string>
#include<cmath>

using namespace std;

int n;
int a[1001];
int dp[1001];
int ret = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i < n; i++) {
		dp[i] = a[i];
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i]) {
				dp[i] = max(dp[i], dp[j] + a[i]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		ret = max(ret, dp[i]);
	}
	cout << ret;
}