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

int n;
int a[201], dp[201];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	dp[0] = a[0];
	int idx = 0;

	for (int i = 1; i < n; i++) {
		if (a[i] > dp[idx]) {
			dp[++idx] = a[i];
		}
		else {
			int tmp = upper_bound(dp, dp + idx, a[i]) - dp;
			dp[tmp] = a[i];
		}
	}

	cout << n - idx - 1;
}
