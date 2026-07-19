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

int n, m;
int a[101];
int c[101];
int dp[10001];

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 10000; j >= c[i]; j--) {
			dp[j] = max(dp[j], dp[j - c[i]] + a[i]);
		}
	}

	for (int i = 0; i <= 10000; i++) {
		if (dp[i] >= m) {
			cout << i;
			break;
		}
	}
}
