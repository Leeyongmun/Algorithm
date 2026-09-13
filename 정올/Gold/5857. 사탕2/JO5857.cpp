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
#include <cctype>
#include <string>
using namespace std;
using ll = long long;

int n, k;
int a[3001];
ll dp[3001][3001];
ll best[3001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	ll ret = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			dp[j][i] = a[j] + a[i];

			if (i - k >= 1) {
				dp[j][i] = max(dp[j][i], dp[min(i - k, j - 1)][j] + a[i]);
			}
			
			ret = max(ret, dp[j][i]);
		} 
		for (int j = 2; j < i; j++) {
			dp[j][i] = max(dp[j][i], dp[j - 1][i]);
		}
	}

	cout << ret;
}
