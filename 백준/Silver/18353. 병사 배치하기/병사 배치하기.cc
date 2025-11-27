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
int a[2001], dp[2001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	dp[0] = a[0];
	int idx = 0;
	for (int i = 1; i < n; i++) {
		if (dp[idx] > a[i]) {
			dp[++idx] = a[i];
		}
		else {
			for (int j = 0; j <= idx; j++) {
				if (dp[j] < a[i]) {
					dp[j] = a[i];
					break;
				}
			}
		}
	}
	cout << n - idx - 1;
}
